from django.contrib.auth import get_user_model
from django.shortcuts import resolve_url
from django.test import TestCase


# Create your tests here.

class IndexViewTests(TestCase):
    def test_get_index(self):
        url = resolve_url("pizza:index")
        response = self.client.get(url)
        self.assertEqual(200, response.status_code)
        self.assertEqual('pizza/index.html', response.template_name)


class AnonymousTests(TestCase):
    def test_get(self):
        url = resolve_url("pizza:dodaj")
        response = self.client.get(url)
        self.assertEqual(302, response.status_code)
        url = resolve_url("auth_login") + "?next=" + url
        self.assertRedirects(response, url)


class UserTestCase(TestCase):
    def setUp(self):
        super(UserTestCase, self).setUp()
        self.user = get_user_model().objects.create(username='admin')
        self.client.force_login(self.user)


class PizzaCreateTests(UserTestCase):
    def test_get(self):
        url = resolve_url("pizza:dodaj")
        response = self.client.get(url)
        self.assertEqual(200, response.status_code)
        self.assertEqual({}, response.context_data['form'].errors)

    def test_post(self):
        url = resolve_url("pizza:dodaj")
        data = {
            'cena': 5,
            'nazwa': 'Hawajska',
            'rozmiar': 'L',
        }
        data['skladniki-INITIAL_FORMS'] = 0
        data['skladniki-TOTAL_FORMS'] = 5
        response = self.client.post(url, data=data)
        self.assertEqual(200, response.status_code)
        self.assertEqual({}, response.context_data['form'].errors)
