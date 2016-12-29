from django.shortcuts import resolve_url
from django.test import TestCase

# Create your tests here.

class IndexViewTests(TestCase):

    def test_get_index(self):
        url = resolve_url("pizza:index")
        response = self.client.get(url)
        self.assertEqual(200, response.status_code)
        self.assertEqual('pizza/index.html', response.template_name)
