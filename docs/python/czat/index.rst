Czat (cz. 2)
#########################

Początek pracy z aplikacjami pisanymi z użyciem Django jest zazwyczaj podobny.
Polega na utworzeniu projektu i aplikacji, likalizacji środowiska, utworzeniu
modelu, uruchomieniu panelu administracyjnego i napisaniu podstawowego widoku.

Wszystkie powyższe czynności opisane zostały w scenariuszu :ref:`Czat (cz. 1) <czat_app>`.
Poniższy materiał jest jego rozwinięciem. Pokażemy w nim alternatywne metody
rozwijania aplikacji, wykorzystujące wbudowane w Django rozwiązania.

Aby rozpocząć pracę nad wersją rozszerzoną wykonaj punkty 5.4.1 – 5.4.4
scenariusza :ref:`Czat (cz. 1) <czat_app>`.


Obsługa użytkowników
***************************

Zamiast dodawać użytkowników w panelu administracyjnym umożliwimy im samodzielne
zakładanie kont w serwisie. Użytkownicy muszą również mieć możliwość logowania
i wylogowywania się. Moglibyśmy te zadania zrealizować tak, jak w cz. 1 scenariusza,
czyli za pomocą osobnych widoków (funkcji), które wyświetlałaby odpowiednie formularze (GET)
oraz obsługiwałaby ich przesyłanie i walidację (POST).
Zamiast tego wykorzystamy zaprojektowane w Django formularze i widoki wbudowane (ang. *generic views*).

Rejestrowanie
=============

Na początku pliku :file:`urls.py` aplikacji czat importujemy formularz tworzenia użytkownika
(``UserCreationForm``) oraz wbudowany widok przenaczony do dodawania danych (``CreateView``):

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: python

    from django.contrib.auth.forms import UserCreationForm
    from django.views.generic.edit import CreateView

Następnie do listy ``paterns`` dopisujemy:

.. raw:: html

    <div class="code_no">Plik <i>urls.py</i>. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: urls.py
    :linenos:
    :lineno-start: 18
    :lines: 18-21

Powyższy kod wiąże adres URL */rejestruj* z wywołaniem widoku wbudowanego jako funkcji
``CreateView.as_view()``. Przekazujemy jej trzy parametry:

* ``template_name`` – szablon, który zostanie użyty do zwrócenia odpowiedzi;
* ``form_class`` – formularz, który zostanie przekazany do szablonu;
* ``success_url`` – adres, na który nastąpi przekierowanie w przypadku braku błędów
  (np. po udanej rejestracji);

Teraz tworzymy szablon formularza rejestracji, który zapisać należy w pliku :file:`czatpro/czat/templates/czat/rejestruj.html`:

.. raw:: html

    <div class="code_no">Plik <i>rejestruj.html</i>. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: rejestruj_z2.html
    :linenos:

Na koniec wstawimy link na stronie głównej, a więc uzupełniamy plik :file:`index.html`:

.. raw:: html

    <div class="code_no">Plik <i>index.html</i>. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: index_z2.html
    :linenos:

.. tip::

    Zwróć uwagę na sposób tworzenia linków w szablonie: ``{% url 'czat:loguj' %}``.
    Nazwe definiowaną w parametrze ``name`` w pliku :file:`urls.py` aplikacji
    poprzedzamy przestrzenią nazw zdefiniowaną w pliku adresów projektu (``namespace='czat'``).

Uruchom aplikację (``python manage.py runserver``) i przetestuj dodawanie użytkowników:
spróbuj wysłać niepełne dane, np. bez hasła; spróbuj dodać dwa razy tego samego użytkownika.

Wy(logowanie)
=============

Na początku pliku :file:`urls.py` aplikacji dopisujemy wymagany import:

.. code-block:: python

    from django.core.urlresolvers import reverse_lazy

– a następnie:

.. raw:: html

    <div class="code_no">Plik <i>urls.py</i>. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: urls.py
    :linenos:
    :lineno-start: 22
    :lines: 22-27

Widać, że z adresami */loguj* i */wyloguj* wiążemy wbudowane w django widoki ``login``
i ``logout`` importowane z modułu ``django.contrib.auth.views``. Jedynym nowym
parametrem jest ``next_page``, za pomocą którego wskazujemy stronę
wyświetlaną po wylogowaniu (``reverse_lazy('czat:index')``).

Logowanie wymaga szablonu :file:`loguj.html`, który tworzymy i zapisujemy w podkatalogu :file:`templates/czat`:

.. raw:: html

    <div class="code_no">Plik <i>loguj.html</i>. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: loguj_z3.html
    :linenos:

Musimy jeszcze określić stronę, na którą powinien zostać przekierowany
użytkownik po udanym zalogowaniu. W tym wypadku na końcu pliku :file:`czatpro/czatpro/settings.py`
definujemy wartość zmiennej ``LOGIN_REDIRECT_URL``:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: python

    # czatpro/czatpro/settings.py

    from django.core.urlresolvers import reverse_lazy
    LOGIN_REDIRECT_URL = reverse_lazy('czat:index')

Na koniec warto uzupełnić plik :file:`index.html` o linki służące do logowania i wylogowania.
Spróbuj zrobić to sam i przetestuj działanie aplikacji.

Lista wiadomości
*****************

Chcemy, by zalogowani użytkownicy mogli przeglądać wiadomości wszystkich użytkowników,
zmieniać, usuwać i dodawać własne. Najprostszy sposób to skorzystanie z wspomnianych
widoków wbudowanych.

.. note::

    Django oferuje wbudowane widoki przeznaczone do typowych operacji:

    * DetailView i ListView – (ang. *generic display view*) widoki przeznaczone
      do prezentowania szczegółów i listy danych;
    * FormView, CreateView, UpdateView i DeleteView – (ang. *generic editing views*)
      widoki przeznaczone do wyświetlania formularzy ogólnych, w szczególności
      służących dodawaniu, uaktualnianiu, usuwaniu obiektów (danych).

Do wyświetlania listy wiadomości użyjemy klasy ``ListView``.
Do pliku :file:`urls.py` dopisujemy importy:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: python

    from django.contrib.auth.decorators import login_required
    from django.views.generic.list import ListView
    from czat.models import Wiadomosc

– i wiążemy adres */wiadomosci* z wywołaniem widoku:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: urls.py
    :linenos:
    :lineno-start: 28
    :lines: 28-34

Zakładamy, że wiadomości mogą oglądać tylko użytkownicy zalogowani. Dlatego
całe wywołanie widoku umieszczamy w funkcji ``login_required()``.

W wywołaniu ``ListView.as_view()`` wykorzystujemy kolejne parametry
modyfikujące działanie widoków:

* ``model`` – podajemy model, którego dane zostaną pobrane z bazy;
* ``context_object_name`` – pozwala zmienić domyślną nazwę (object_list)
  listy obiektów przekazanych do szablonu;
* ``paginate_by``– pozwala ustawić ilość obiektów wyświetlanych na stronie.

Parametr ``login_url`` określa adres, na który przekierowany zostanie
niezalogowany użytkownik.

.. raw:: html

    <hr />

Potrzebujemy szablonu, którego Django szuka pod domyślną nazwą
*<nazwa modelu>_list.html*, czyli w naszym przypadku tworzymy plik
:file:`~/czatpro/czat/templates/czat/wiadomosc_list.html`:

.. raw:: html

    <div class="code_no">Plik <i>wiadomosc_list.html</i>. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: wiadomosc_list_z4.html
    :linenos:

Kolejne wiadomości odczytujemy i wyświetlamy w pętli przy użyciu tagu ``{% for %}``.
Dostęp do właściwości obiketów umożliwia operator kropki, np.: ``{{ wiadomosc.autor.username }}``.

Zanim przetestujesz wyświetlanie wiadomości, dodaj link na stronie głównej!

Dodawanie wiadomości
********************

Zadanie to zrealizujemy wykorzystując widok ``CreateView``. Aby ułatwić
dodawanie wiadomości **dostosujemy klasę widoku** tak, aby użytkownik
nie musiał wprowadzać pola autor.

Na początek dopiszemy w pliku :file:`urls.py` skojarzenie adresu URL
*wiadomosc/* z wywołaniem klasy ``CreateView`` jako funkcji:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: urls.py
    :linenos:
    :lineno-start: 35
    :lines: 35-38

Dalej kodujemy w pliku :file:`views.py`. Na początku dodajemy importy:

.. code-block:: python

    from django.views.generic.edit import CreateView
    from czat.models import Wiadomosc
    from django.utils import timezone

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: views.py
    :linenos:
    :lineno-start: 18
    :lines: 18-38

Dostosowując widok ogólny, tworzymy opartą na nim klasę ``UtworzWiadomosc``.
Nieomówiona dotąd właściwość ``fields`` pozwala wskazać pola, które mają znaleźć
się na formularzu. Jak widać, pomijamy pole ``autor``.

Pole to jest jednak wymagane. Aby je uzupełnić, napisujemy metodę
``form_valid()``, która sprawdza poprawność przesłanych danych i zapisuje je w bazie:

* ``wiadomosc = form.save(commit=False)`` – tworzymy obiekt wiadomości, ale go nie zapisujemy;
* ``wiadomosc.autor = self.request.user`` – uzupełniamy dane autora;
* ``wiadomosc.save()`` – zapisujemy obiekt.

Metoda ``get_initial()`` pozwala ustawić domyślne wartości dla wybranych pól.
Wykorzystujemy ją do zainicjowania pola ``data_pub`` aktualna datą (``initial['data_pub'] = timezone.now()``).

Metoda ``get_context_data()`` z punktu widzenia dodawania wiadomości
nie jest potrzebna. Pozwala natomiast przekazać do szablonu dodatkowe dane,
w tym wypadku jest to lista wiadomości utworzonych przez zalogowanego
użytkownika: ``Wiadomosc.objects.filter(autor=self.request.user)``.
Będzie można wyświetlić je poniżej formularza dodawania nowej wiadomości.

.. raw:: html

    <hr />

Domyślny szablon dodawania danych nazywa się *<nazwa modelu>_form.html*. Możemy go utworzyć
na podstawie szablonu :file:`wiadomosc_list.html`. Otwórz go i zapisz pod nazwą
:file:`wiadomosc_form.html`. Przed listą wiadomości umieść kod wyświetlający formularz:

.. raw:: html

    <div class="code_no">Plik <i>wiadomosc_form.html</i>. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: wiadomosc_form_z4.html
    :linenos:
    :lineno-start: 6
    :lines: 6-11

Zanim przetestujesz dodawanie wiadomości, dodaj odpowiedni link na stronie głównej!

.. figure:: img/czat19wiadomosci.png

Edycja wiadomości
*****************

Widok pozwalający na edycję wiadomości i jej aktualizację dostępny będzie
pod adresem ***/edytuj/id_wiadomości***, gdzie *id_wiadomosci* będzie identyfikatorem
obiektu do zaktualizowania. Zaczniemy od uzupełnienia pliku :file:`urls.py`:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: urls.py
    :linenos:
    :lineno-start: 39
    :lines: 39-42

Nowością w powyższym kodzie są wyrażenia regularne definiujące adresy z dodatkowym
parametrem, np. ``r'^edytuj/(?P<pk>\d+)/'``. Część ``/(?P<pk>\d+)`` oznacza,
że oczekujemy 1 lub więcej cyfr (``\d+``), które zostaną zapisane w zmiennej o nazwie
``pk`` (``?P<pk>``) – nazwa jest tu skrótem od ang. wyrażenia *primary key*, co znaczy
"klucz główny". Zmienna ta zawierać będzie identyfikator wiadomości i dostępna
będzie w klasie ``EdytujWiadomosc``, która dziedziczy, czyli dostosowuje wbudowany
widok ``UpdateView``.

Na początku pliku :file:`views.py` importujemy więc potrzebny widok:

.. code-block:: python

    from django.views.generic.edit import UpdateView

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: views.py
    :linenos:
    :lineno-start: 41
    :lines: 41-56

Najważniejsza jest tu metoda ``get_object()``, która pobiera i zwraca wskazaną przez
identyfikator w zmiennej *pk* wiadomość: ``wiadomosc = Wiadomosc.objects.get(id=self.kwargs['pk'])``.
Omawianą metodę ``get_context_data()`` wykorzystujemy tak jak poprzednio, tzn. aby przekazać
do szablonu listę wiadomości zalogowanego użytkownika (``Wiadomosc.objects.filter(autor=self.request.user)``).

Właściwości ``model``, ``context_object_name``, ``template_name`` i ``success_url``
wyjaśniliśmy wcześniej. Jak widać, do edycji wiadomości można wykorzystać ten sam szablon,
którego użyliśmy podczas dodawania.

Formularz jednak dostosujemy. Tym razem wykorzystamy właściwość ``form_class``,
której przypisujemy utworzoną w nowym pliku :file:`forms.py` klasę zmieniającą
domyślne ustawienia:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: forms_z5.py
    :linenos:

Klasa ``EdytujWiadomoscForm`` oparta jest na wbudowanej klasie ``ModelForm``.
Właściwości formularza określamy w podklasie ``Meta``:

* ``model`` – oznacza to samo co w widokach, czyli model, dla którego tworzony jest formularz;
* ``fields`` – to samo co w widokach, lista pól do wyświetlenia;
* ``exclude`` – opcjonalnie lista pól do pominięcia;
* ``widgets`` – słownik, którego klucze oznaczają pola danych, a ich wartości
  odpowiadające im w formularzach HTML typy pól i ich właściwości, np. rozmiar.

Żeby przetestować aktualizowanie wiadomości, w szablonie :file:`wiadomosc_list.html`
trzeba wygenerować linki *Edytuj* dla wiadomości utworzonych przez zalogowanego użytkownika.
Wstaw w odpowiednie miejsce szablonu poniższy kod:

.. raw:: html

    <div class="code_no">Plik wiadomosc_lista.html nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: wiadomosc_list_z5.html
    :linenos:
    :lineno-start: 12
    :lines: 12-14

Dodaj również te same linki do listy wiadomości na stronach dodawania i aktualizowania.

.. figure:: img/czat18wiadomosci.png

Usuwanie wiadomości
*******************

**Usuwanie danych** realizujemy za pomocą widoku ``DeleteView``, który importujemy
na początku pliku :file:`urls.py`:

.. code-block:: python

    from django.views.generic import DeleteView

Podobnie, jak w przypadku edycji, usuwanie powiążemy z adresem URL zawierającym
identyfikator wiadomości ***/usun/id_wiadomości***. W pliku :file:`urls.py` dopisujemy:


.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: urls.py
    :linenos:
    :lineno-start: 43
    :lines: 43-49

Warto zwrócić uwagę, że podobnie jak w przypadku listy wiadomości, o ile wystarcza nam
domyślna funkcjonalność widoku wbudowanego, nie musimy niczego implementować w pliku :file:`views.py`.

Domyślny szablon dla tego widoku przyjmuje nazwę *<nazwa-modelu>_confirm_delete.html*,
dlatego uproścliśmy jego nazwę we właściwości ``template_name``. Tworzymy więc plik
:file:`wiadomosc_usun.html`:

.. raw:: html

    <div class="code_no">Plik <i>wiadomosc_usun.html</i>. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: wiadomosc_usun_z6.html
    :linenos:

Tag ``{{ object }}`` zostanie zastąpiony treścią wiadomoś zwróconą przez funkcję
"autoprezentacji" ``__unicode__()`` modelu.

Na koniec, podobnie jak w przypadku edycji wiadomości, trzeba dodać linki *Usuń* w szablonach wyświetlających
listę wiadomości. Spróbuj zrobic to samodzielnie, a następnie przetestuj działanie aplikacji.

.. figure:: img/czat20wiadomosci.png

Szablony
*****************

Zapewne zauważyłeś, że większość kodu w szablonach, a zatem i w stronach
HTML, które z nich powstają, się powtarza, albo jest bardzo podobna.
Biorąc pod uwagę schematyczną budowę stron WWW jest to nieuniknione.
Django dysponuje wbudowanym silnikiem szablonów, który ułatwia ich tworzenie.

Szablony, jak można było zauważyć, składają się ze zmiennych i tagów.
Zmienne, które ujmowane są w podwójne nawiasy sześciokątne ``{{ zmienna }}``,
zastępowane są konkretnymi wartościami. Tagi z kolei, oznaczane notacją
``{% tag %}`` tworzą mini-język szablonów i pozwalają kontrolować logikę budowania treści.
Najważniejsze tagi, ``{% if warunek %}``, ``{% for wyrażenie %}``, ``{% url nazwa %}``
– już stosowaliśmy.

Spróbujmy uprościć i ujednolicić nasze szablony. Zacznijmy od szablonu
bazowego, który umieścimy w pliku :file:`~/czat/czat/templates/czat/baza.html`:

.. raw:: html

    <div class="code_no">Plik baza.html nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: baza_z10.html
    :linenos:

Jest to zwykły tekstowy dokument, zawierający schemat strony utworzony z
wymaganych znaczników HTML oraz bloki zdefiniowane za pomocą tagów mini-języka
szablonów. W pliku tym umieszczamy stałą i wspólną strukturę stron w serwisie
(np. nagłówek, menu, sekcja treści, stopka itp.) oraz wydzielamy bloki,
których treść będzie można zmieniać w szablonach konkretnych stron.

Wykorzystując szablon podstawowy, zmieniamy stronę główną, czyli plik
:file:`index.html`:

.. raw:: html

    <div class="code_no">Plik index.html nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: index_z10.html
    :linenos:

Jak widać, szablon dziedziczy z szablonu bazowego. Odpowiada za to tag
``{% extends plik_bazowy %}``. Dalej pomijamy strukturalne znaczniki HTML
zdefiniowane w bazie, zastępujemy natomiast zawartość bloków, które
uznajemy za potrzebne na danej stronie.

Postępując na tej samej zasadzie modyfikujemy szablon rejestracji:

.. raw:: html

    <div class="code_no">Plik rejestruj.html nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: rejestruj_z10.html
    :linenos:

Ćwiczenie 9
==============

Wzorując się na podanych przykładach zmień pozostałe szablony tak, aby
opierały się na szablonnie bazowym. Wygląd stron nie powinien ulec zmianie!

Style, skrpyty, pliki
************************

Nasze szablony zyskały na zwięzłości i przejrzystości, ale nadal pozbawione
są elementarnych dla dzisiejszych stron WWW zasobów, takich jak
style CSS, skrypty JavaScript czy zwykłe obrazki. Jak je dołączyć?

Przede wszystkim potrzebujemy osobnego katalogu :file:`~czat/czat/static/czat`.
W terminalu w katalogu projektu (!) wydajemy polecenie:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: bash

    ~/czat $ mkdir -p czat/static/czat

W powyższym katalogu tworzy się zazwyczaj podkatalogi dla różnych typów
zasobów, np. :file:`css`, :file:`js` czy :file:`img`. Sugerujemy, żeby
je utworzyć. Tworzymy również przykładowy plik :file:`~/czat/czat/static/czat/css/style.css`:

.. raw:: html

    <div class="code_no">Plik style.css nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: css
.. literalinclude:: style_z11.css
    :linenos:

Do podkatalogu :file:`~/czat/czat/static/czat/img` wrzucamy obrazki z podanego
:download:`archiwum <img.zip>`. Wreszcie zmieniamy szablon podstawowy:

.. raw:: html

    <div class="code_no">Plik baza.html nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: baza_z11.html
    :linenos:
    :lines: 2, 7-8, 33-37

Kod z linii 1. ``{% load staticfiles %}`` umieszczamy na samym początku
dokumentu. Konfiguruje on ścieżkę do zasobów. Kod z linii 3. wklejamy
za znacznikiem ``<title>`` w sekcji ``<head>``. Ilustruje on, jak dołączamy
style czy skrypty, mianowicie używamy tagu ``{% static plik %}``. Wreszcie
kod z linii 5-8 zawierający znacznik ``<div>`` z obrazkami wstawiamy
na końcu pliku przed znacznikiem zamykającym ``</body>``. Widzimy tu,
jak wstawiać obrazki. Wygląd strony głównej po zmianach:

.. figure:: img/czat22szabl.png

Ćwiczenie 10
==============

W szablonie bazowym stwórz osobny block umożliwiający zastępowanie wstawionych
obrazków. Zmień dowolny szablon inny niż strona główna tak, aby wyświetlał
inne obrazki. Pamiętaj o zapisaniu dodatkowych obrazków do odpowiedniego katalogu!

.. tip::

    Tag ``{% load staticfiles %}`` musisz wstawić do każdego szablonu
    (w dowolnym miejscu), w którym chcesz odwoływać się do plików
    z katalogu :file:`static`.

.. figure:: img/czat23szabl.png

Na powyższym zrzucie widać wykonane ćwiczenie, czyli użycie dodatkowych
obrazków. Jednak strona nie wygląda dobrze, ponieważ treść podpowiedzi
nachodzi na logo Django (oczywiście przy małym rozmiarze okna przeglądarki).
Spróbujemy temu zaradzić.

Wykorzystamy prosty skrypt JQuery. Na początku ściągnij bibliotekę i skrypt
z podanego :download:`archiwum <js.zip>`. Rozpakuj pliki do katalogu
:file:`static/js`. Następnie do szablonu podstawowego :file:`baza.html`
dodaj przed tagiem zamykającym ``</body>`` kod:

.. raw:: html

    <div class="code_no">Plik baza.html nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: baza_z12.html
    :linenos:
    :lines: 39-40

Po odświeżeniu strony powinnieneś zobaczyć poprawioną stronę:

.. figure:: img/czat24szabl.png

cdn.

Materiały
***************

Słownik
================

.. include:: ../glossary.rst

1. O Django http://pl.wikipedia.org/wiki/Django_(informatyka)
2. Strona projektu Django https://www.djangoproject.com/
3. Co to jest framework? http://pl.wikipedia.org/wiki/Framework
4. Co nieco o HTTP i żądaniach GET i POST http://pl.wikipedia.org/wiki/Http

Źródła
===========

* :download:`czat_pr.zip <czat_pr.zip>`

Metryka
===============

:Autor: Robert Bednarz

:Utworzony: |date| o |time|

.. |date| date::
.. |time| date:: %H:%M

.. raw:: html

    <style>
        div.code_no { text-align: right; background: #e3e3e3; padding: 6px 12px; }
        div.highlight, div.highlight-python { margin-top: 0px; }
    </style>
