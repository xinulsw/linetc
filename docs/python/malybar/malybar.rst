Django
#######

`Django <https://www.djangoproject.com/>`_ to napisany w Pythonie framework
przeznaczony do szybkiego tworzenia aplikacji internetowych.
Został zaprojektowany przez zespół doświadczonych praktyków w taki sposób,
żeby odciążyć programistę od wykonywania typowych, a jednocześnie uciążliwych czynności.
Zalety Django to szybkość, bezpieczeństwo i skalowalność. Inne cechy wymienione są
na polskiej stronie Wikipedii: `Django (framework) <https://pl.wikipedia.org/wiki/Django_(framework)>`_.

Przygotowanie środowiska
========================

Do pracy z Django potrzebny jest przede wszystkim **interpreter Pythona 2.7.x**.
Jest on domyślnie obecny w systemach Linux. Natomiast w systemach Windows i Mac OS X
należy wejść na stronę `Donwload Python <https://www.python.org/downloads/>`_,
pobrać odpowiedni instalator (32- lub 64-bitowy) Pythona (**wersja 2.7.x**!)
i zainstalować. Opis instalacji znajdziesz na stronie `Interpreter Pythona <http://python101.readthedocs.io/pl/latest/env/windows.html#inerpreter-pythona>`_.

Poza Pythonem potrzebny jest również instalator pakietów Pythona `pip`.
W systemach Linux wywodzących się z Debiana (Ubuntu, Linux Mint)
wystarczy wydać w terminalu polecenie:

.. code-block:: bash

    ~$ sudo apt install python-pip

W systemie Windows `pip` jest instalowany razem z interpreterem.
Korzystając z omawianego narzędzia wydajemy w konsoli tekstowej polecenie:

.. code-block:: bash

    ~$ sudo pip install virtualenv

Narzędzie `virtualenv` posłuży nam do przygotowania **wyizolowanego środowiska Pythona**,
zawierającego wybraną wersję Django. W konsoli wydajemy polecenia:

.. code-block:: bash

		~$ virtualenv dj_10_4
		~$ cd dj_10_4
		~$ source ./bin/activate
		~$ pip install Django==1.10.4
		~$ pip install django-registration

Pierwsze polecenie tworzy katalog zawierający najważniejsze komponenty Pythona.
Nazwa :file:`dj_10_4` jest umowna, w założeniu ma być skrótem wskazującym wykorzystaną
wersję Django. Aby skorzystać z przygotowanego środowiska, należy
go zawsze na początku aktywować, wydając w utworzonym katalogu polecenie ``source ./bin/activate``.
Opuszczenie środowiska umożliwia komenda ``deactivate``.

Polecenia ``pip install ...`` instalują wskazaną wersję Django oraz dodatkową aplikację
ułatwiającą zarządzanie użytkownikami. Tak zainstalowane moduły będą dostępne
tylko w akywowanym środowisku.

**Ćwiczenie**

Zgodnie z powyższym opisem przygotuj samodzielnie wirtualne środowisko do pracy z Django.

.. tip::

	Projektując aplikację będziemy często korzystać z poleceń wydawanych w katalogu
	:file:`dj_10_4` w terminalu. Nie zamykaj więc okna terminala.

Projekt, serwer, aplikacja
==========================

Otwórz terminal, przejdź do katalogu z utworzonym wcześniej wirtualnym środowiskiem
:file:`dj_10_4` i aktywuj go. Utworzymy teraz projekt i uruchomimy serwer deweloperski.
Wydajemy polecenia:

.. code-block:: bash

    ~$ django-admin stratproject malybar
    ~$ cd malybar
    ~$ python manage.py runserver

Tyle wystarczy, żeby utworzyć szkielet serwisu i uruchomić serwer deweloperski,
który możemy wywołać wpisując w przeglądarce adres: ``127.0.0.1:8000``.
Serwer zatrzymujemy naciskając w terminalu skrót :kbd:`CTRL+C`.

.. image:: img/django01.jpg

W ramach jednego projektu (serwisu internetowego) może działać wiele aplikacji.
Pierwszą utworzymy poleceniem:

.. code-block:: bash

	~/malybar$ python manage.py startapp pizza

– w wyniku jego działania w katalogu :file:`pizza` powstanie szkielt aplikacji.

.. tip::

	Katalog :file:`malybar` będziemy nazywać **katalogiem projektu**, natomiast katalog
	:file:`pizza` – **katalogiem aplikacji**.

Zajrzyjmy do katalogu naszego projektu. W terminalu wydajemy polecenie ``tree`` lub
jeżeli go nie ma ``ls -R``.

.. figure:: img/django03.jpg

.. note::

		Katlog projektu :file:`malybar` zawiera:

		- bazę, czyli plik :file:`db.sqlite3`; domyślnym systemem bazodanowym jest SQLite3;
		- skrypt Pythona :file:`manage.py` służy do zarządzania projektem;
		- :file:`settings.py` – zawiera konfigurację projektu;
		- :file:`urls.py` – to swego rodzaju menu naszego projektu, a więc lista wpisów
		  definiująca adresy URL dostępne w naszym projekcie;
		- :file:`wsgi.py` – plik konfiguracyjny wykorzystywany przez serwery WWW.


		W katalogu aplikacji :file:`pizza` znajdziemy:

		- :file:`apps.py` – ustawienia aplikacji;
		- :file:`admin.py` – konfigurację panelu administracyjnego;
		- :file:`models.py` – plik definiujący modele danych przechowywanych w bazie;
		- :file:`views.py` – plik zawierający funkcje, tzw. *widoki*, obsługujące zdefiniowane
		  w plikach :file:`urls.py` adresy.

		Wszystkie katalogi zawierają również plik :file:`__init__.py` wskazujący, że dany
		katalog jest modułem Pythona.

Po utworzeniu szkieletu aplikacji wykonujemy opisane niżej czynności.

1. Edytujemy plik ustawień projektu :file:`malybar/settings.py`, a w nim:
	- rejestrujemy aplikację pizza dopisując jej konfigurację do listy INSTALLED_APPS;
		przy okazji widzimy, że domyślnie na liście znajdują się już aplikacje dostarczane
		przez framework;
	- ustawiamy polską strefę czasową i polski język

	.. code-block:: python

			INSTALLED_APPS = [
			    'pizza.apps.PizzaConfig',
			    'django.contrib.admin',
			    'django.contrib.auth',
			    'django.contrib.contenttypes',
			    'django.contrib.sessions',
			    'django.contrib.messages',
			    'django.contrib.staticfiles',
			]
			...
			LANGUAGE_CODE = 'pl'
			TIME_ZONE = 'Europe/Warsaw'
			...

2.	Włączamy mapowanie adresów aplikacji pizza do pliku projektu :file:`malybar/urls.py`:

	.. code-block:: python

			urlpatterns = [
			    url(r'^', include('pizza.urls', namespace='pizza')),
			    url(r'^pizza/', include('pizza.urls', namespace='pizza')),
			    url(r'^admin/', admin.site.urls),
			]

wyjaśninie funkcji ``url()``, parametry obowiązkowe to `regex` i `view`, opcjonalne `kwargs` i `name`
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

