Django cz. 1
#############

Wstęp nt. czym jest Django


Strona i aplikacja
==================

W wybranym katalogu, np. domowym, wydajemy polecenia:

.. code-block:: bash

    $ django-admin stratproject moja_str
    $ cd moja_strona
    $ python manage.py runserver

Tyle wystarczy, żeby utworzyć szkielet serwisu i uruchomić serwer deweloperski,
który możemy wywołać wpisując w przeglądarce adres: ``127.0.0.1:8000``.

[zrzut]

W ramach jednej strony (serwisu) może działać wiele aplikacji. Jedną utworzymy
poleceniem:

.. code-block:: bash

	$ python manage.py startapp moja_apl

Następnie należy:

- zmodyfikować plik :file:`moja_str/urls.py`  – włączyć :file:`moja_apl/urls.py`
- wyjaśninie funkcji ``url()``, parametry obowiązkowe to `regex` i `view`, opcjonalne `kwargs` i `name`
- w pliku :file:`moja_str/settings.py` wybieramy bazę danych (domyślnie SQLite3), ustawiamy ``TIME_ZONE = 'Europe/Warsaw'`` oraz ``LANGUAGE_CODE = 'pl'``
- ponownie uruchomić serwer

Dostęp do aplikacji możesz zweryfikować wpisując adres: ``127.0.0.1:8000/moja_apl``.

[zrzut]

Model danych
============

Django jest wyposażone we własny system ORM (ang.), służący zarówno do definiowania,
jak i zarządzania źródłami danych.

W pliku :file:`moja_apl/models.py` definiujemy klasę(y) opisującą(e) źródła danych aplikacji.
Odpowiadają one tablom w bazie danych. Każda klasa zawiera pola opisujące przechowywane w nich
informacje. Pola odpowiadają kolumnom w tabelach.

Po zdefiniowaniu modelu danych należy go aktywować, co wymaga włączenia aplikacji do naszej strony. Uzupełniamy więc listę ``INSTALLED_APPS`` w pliku :file:`moja_str/settings.py`, która
na początku zawiera już kilka domyślnie włączonych aplikacji. Dodajemy do niej ścieżkę do ustawień naszej:

.. code-block:: python

	INSTALLED_APPS = [
			'moja_apl.apps.PollsConfig',  # podświetlenie
	    'polls.apps.PollsConfig',
	    'django.contrib.admin',
	    'django.contrib.auth',
	    'django.contrib.contenttypes',
	    'django.contrib.sessions',
	    'django.contrib.messages',
	    'django.contrib.staticfiles',
	]

Następnie tworzymy tzw. *migrację*, czyli informację o zmianie modelu naszej aplikacji.

.. code-block:: bash

    $ python manage.py make migrations moja_apl
    $ python manage.py sqlmigrate moja_apl 0001
    $ python manage.py migrate

Drugie opcjonalne polecenie pozwala zobaczyć klauzule SQL-a, które zostaną użyte do wprowadzenia
zdefiniowanych w modelu zmian do bazy. Ostatnie polecenie na podstawie migracji wszystkich
zarejestrowanych aplikacji tworzy bazę danych, a w niej odpowiednie tabele.

Testowanie modelu
-----------------

Po zdefiniowaniu modelu możemy go od przetestować w konsoli, zanim wykorzystamy
go w aplikacji.

.. code-block:: bash

    $ python manage.py shell

Powyższe polecenie uruchamia konsolę Pythona (rozszerzoną, jeżeli jest dostępna) i tworzy
środowisko testowe. Zobaczmy, jak za pomocą bazodanowego API zarządzać danymi.
Na początku **tworzenie danych** (ang. *create*):

.. code-block:: bash

	$ pytanie = Pytanie(tresc="Jak się nazywasz?")
	$ pytanie.save()
	$ print pytanie.id, pytanie.tresc, pytanie.data_pub

[zrzut]

.. code-block:: bash

	$ from django.utils import timezone
	$ pytanie = Pytanie(tresc="Gdzie mieszkasz??", data_pub=timezone.now())
	$ pytanie.save()
	$ print pytanie.id, pytanie.tresc, pytanie.data_pub

Przećwiczmy też **wydobywanie danych** (ang. *read*) z bazy:

.. code-block:: bash

	$ pytania = Pytanie.objects.all()
	$ print pytania
	$ print pytania[0].id, pytania[0].tresc, pytania[0].data_pub
	$ pytanie = Pytanie.objects.get(pk=2)
	$ print pytanie.tresc
	$ Pytanie.objects.filter(data_pub__year=timezone.now().year)
	$ Pytanie.objects.filter(tresc__startswith='Kiedy')
	$ Pytanie.objects.count()

Strona administracyjna
======================

Zarządzanie treściami czy użytkownikami wymaga panelu administracyjnego, Django dostarcza nam
go automatycznie. Na początku tworzymy konto administratora:

.. code-block:: bash

    $ python manage.py createsuperuser

Django zapyta o nazwę, e-mail i hasło. Podajemy: “admin”, “” (pomijamy), “admin”.
Jeżeli chcemy mieć możliwość dodawania treści, w pliku :file:`moja_apl/admin.py`
importujemy nasz(e) model(e) i rejestrujemy go(je):

.. highlight:: python
.. literalinclude:: admin_01.py
    :linenos:
    :lineno-start: 1
    :lines: 1-

**Ćwiczenie**

Uruchom serwer, a w przeglądarce wpisz adres: ``127.0.0.1:8000/admin``.
Po zalogowaniu się dodaj dwa pytania. Następnie utwórz konto dla użytkownika "uczen"
z hasłem "q1w2e3". Przydziel mu prawa do dodawania, modyfikowania i usuwania pytań.
Przeloguj się na konto "uczen" i dodaj jeszcze dwa pytania.

[zrzut]

