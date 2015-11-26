Czat (wersja rozszerzona)
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

    <div class="code_no">Plik *urls.py*. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: urls.py
    :linenos:
    :lineno-start: 21
    :lines: 21-24

Powyższy kod wiąże adres URL */rejestruj* z wywołaniem widoku wbudowanego jako funkcji
``CreateView.as_view()``. Przekazujemy jej trzy parametry:

* ``template_name`` – szablon, który zostanie użyty do zwrócenia odpowiedzi;
* ``form_class`` – formularz, który zostanie przekazany do szablonu;
* ``success_url`` – adres, na który nastąpi przekierowanie w przypadku braku błędów
  (np. po udanej rejestracji);

Teraz tworzymy szablon formularza rejestracji, który zapisać należy w pliku :file:`czatpro/czat/templates/czat/rejestruj.html`:

.. raw:: html

    <div class="code_no">Plik *rejestruj.html*. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: rejestruj_z2.html
    :linenos:

Na koniec wstawimy link na stronie głównej, a więc uzupełniamy plik :file:`index.html`:

.. raw:: html

    <div class="code_no">Plik *index.html*. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: index_z2.html
    :linenos:

.. info::

    Zwróć uwagę na sposób tworzenia linków w szablonie: ``{% url 'czat:loguj' %}``.
    Nazwe definiowaną w parametrze ``name`` w pliku :file:`urls.py` aplikacji
    poprzedzamy przestrzenią nazw zdefiniowaną w pliku adresów projektu (``namespace='czat'``).

Ćwiczenie 1
============

Uruchom aplikację (``python manage.py runserver``) i przetestuj dodawanie użytkowników:
spróbuj wysłać niepełne dane, np. bez hasła; spróbuj dodać dwa razy tego samego użytkownika.

Wy(logowanie)
=============

Na początku pliku :file:`urls.py` aplikacji dopisujemy wymagany import:

.. code-block:: python

    from django.core.urlresolvers import reverse_lazy

– a następnie:

.. raw:: html

    <div class="code_no">Plik *urls.py*. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: urls.py
    :linenos:
    :lineno-start: 25
    :lines: 25-30

Widać, że z adresami */loguj* i */wyloguj* wiążemy wbudowane w django widoki ``login``
i ``logout`` importowane z modułu ``django.contrib.auth.views``. Jedynym nowym
parametrem jest ``next_page``, za pomocą którego wskazujemy stronę
wyświetlaną po wylogowaniu (``reverse_lazy('czat:index')``).

Logowanie wymaga szablonu :file:`loguj.html`, który tworzymy i zapisujemy w podkatalogu :file:`templates/czat`:

.. raw:: html

    <div class="code_no">Plik *loguj.html*. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

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
    :lineno-start: 31
    :lines: 31-37

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
====================

Zadanie to zrealizujemy wykorzystując widok ``CreateView``.
Ponieważ nasz model wiadomości zawiera klucz obcy, mianowicie pole autor,
tym razem dostosujemy klasę widoku w pliku :file:`views.py`. Dzięki temu
będziemy mogli rozszerzyć funkcjonalność standardową.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: views.py
    :linenos:
    :lineno-start: 58
    :lines: 58-

Dostosowując widok ogólny tworzymy opartą na nim klasę ``UtworzWiadomosc``.
Z nieomówionych dotąd ustawień widoku widzimy właściwość ``fields`` –
pozwala ona określić w postaci listy pola, które mają znaleźć się na formularzu.
Jak widać, pomijamy pole ``autor``.

Właśnie dlatego musimy nadpisać metodę ``form_valid()``, która sprawdza
poprawność przesłanych danych i zapisuje je w bazie. Żądanie POST otrzymane od
użytkownika nie będzie zawierało danych autora. Musimy je uzupełnić.
Polecenie ``wiadomosc = form.save(commit=False)`` tworzy obiekt wiadomości,
ale go nie zapisuje. Dzięki temu w następnych instrukcjach możemy
uzupełnić dane autora, po czym jeszcze raz zapisujemy wiadomość, tym razem w bazie.

Metoda ``get_initail()`` pozwala ustawić domyślne wartości dla wybranych
pól. Wykorzystujemy ją do zainicjowania pola ``data_pub`` aktualna datą.

Metoda ``get_context_data()`` z punktu widzenia dodawania wiadomości
nie jest potrzebna, ale używamy jej po to, aby na jednej stronie
obok formularza dodawania wiadomości wyświetlić ich listę. Inicjujemy
ją poleceniem ``Wiadomosc.objects.filter(autor=self.request.user)``
wybierającym wiadomości utworzone przez zalogowanego użytkownika.


Ćwiczenie 5
==============

Podobnie jak wyżej potrzebujemy szablonu, który dla widoków dodawania domyślnie
nazywają się *<nazwa modelu>_form*. Na podstawie szablonu ``wiadomosc_list.html``
utwórz szablon  ``wiadomosc_form.html``>. Przed listą wiadomości umieść
kod wyświetlający formularz:

.. raw:: html

    <div class="code_no">Plik wiadomosc_form.html nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: wiadomosc_form_z7.html
    :linenos:
    :lineno-start: 14
    :lines: 14-19

.. figure:: img/czat19wiadomosci.png

Dodamy teraz dwa widoki przeznaczone do aktualizaowania i usuwania wpisów.
Zakładamy, że adresy do tych operacji będą miały postać: */aktualizuj/id_wiadomości*
oraz */usun/id_wiadomości*, gdzie *id_wiadomosci* jest identyfikatorem
obiektu do zaktualizowania/usunięcia. Tym razem zaczniemy od zmian w pliku :file:`urls.py`:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: urls_z8.py
    :linenos:
    :lineno-start: 42
    :lines: 42-50

Nowością w powyższym kodzie są wyrażenia regularne definiujące adresy z dodatkowym
parametrem, np. ``r'^aktualizuj/(?P<pk>\d+)/'``. Część ``/(?P<pk>\d+)`` oznacza,
że oczekujemy liczby dziesiętnej, która zostanie zapisana do zmiennej o nazwie
``pk`` – nazwa jest tu skrótem od ang. wyrażenia *primary key*, co znaczy
"klucz główny". Zmienna ta oznaczać będzie identyfikator wiadomości i dostępna
będzie w widokach.

**Usuwanie danych** realizujemy za pomocą widoku ``DeleteView``, który należy
zaimportować w pliku :file:`urls.py`: ``from django.views.generic.edit import DeleteView``.
Domyślny szablon dla tego widoku przyjmuje nazwę *<nazwa-modelu>_confirm_delete.html*,
dlatego uproścliśmy jego nazwę we właściwości ``template_name``.

Ćwiczenie 6
==============

Utwórz szablon :file:`wiadomosc_usun.html` wzorując sie na wcześniejszych
szablonach. Zamiast instrukcji wyświetlającej formularz umieść kod:

.. raw:: html

    <div class="code_no">Plik wiadomosc_usun.html nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: wiadomosc_usun_z8.html
    :linenos:
    :lineno-start: 17
    :lines: 17

.. figure:: img/czat20wiadomosci.png

Nieco więcej pracy wymaga **dostosowanie widoku aktualizacji**. W pliku
:file:`views.py` utworzymy klasę ``AktualizujWiadomosc`` opartą na
widoku ogólnym ``UpdateView``:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: views_z8.py
    :linenos:
    :lineno-start: 85
    :lines: 85-102

Formularz generowany przez Django dla danego widoku można dostosować.
Odpowiada za to właściwość ``form_class``, której przypisujemy utworzoną
w nowym pliku :file:`forms.py` klasę modyfikującą domyślne ustawienia:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: forms_z8.py
    :linenos:

Klasa ``AktualizujWiadomoscForm`` oparta jest na wbudowanej klasie ``ModelForm``.
Właściwości podklasy ``Meta`` pozwalają określić cechy formularza
wyświetlanego przez widok, który go wykorzystuje:

* ``model`` – oznacza to samo co w widokach, czyli model, dla którego tworzony jest formularz;
* ``fields`` – to samo co w widokach, lista pól do wyświetlenia;
* ``exclude`` – opcjonalnie lista pól do pominięcia;
* ``widgets`` – słownik, którego klucze oznaczają pola danych, a ich wartości
  odpowiadające im w formularza HTML typy pól i ich właściwości, np. rozmiar.

Na wyjaśnienie zasługuje jeszcze metoda ``get_object()`` widoku aktualizacji.
Jej zadanie to wybranie z bazy danych i zwrócenie do formularza wiadomości,
której identyfikator został przekazany w adresie pod nazwą *pk*:
``wiadomosc = Wiadomosc.objects.get(id=self.kwargs['pk'])``.

Ćwiczenie 7
==============

Żeby przetestować aktualizowanie i usuwanie wiadomości, w szablonie
:file:`wiadomosc_list.html` wygeneruj linki *Edytuj* i *Usuń* tylko
dla wiadomości utworzonych przez zalogowanego użytkownika.

Wstaw w odpowiednie miejsce szablonu poniższy kod:

.. raw:: html

    <div class="code_no">Plik wiadomosc_lista.html nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: wiadomosc_list_z8.html
    :linenos:
    :lineno-start: 20
    :lines: 20-23

Dodaj również te same linki do listy wiadomości na stronach dodawania i aktualizowania.

.. figure:: img/czat18wiadomosci.png

Wiadomości jeszcze raz
************************

Dodawanie wiadomości można zrealizować bez wbudowanych widoków ogólnych.
Potrzebować będziemy widoku o nazwie np. ``wiadomosci()`` do wyświetlania
(żądania GET) i dodawania wiadomości (żądania POST), który zwracał będzie
szablon np. :file:`wiadomosci.html`. Widok ten powiążemy z adresem */wiadomosci*.
Do pliku :file:`views.py` dodajemy importy i kod funkcji:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: views_z9.py
    :linenos:
    :lineno-start: 105
    :lines: 105-

Widać powyżej, że treść przesłanej wiadomości wydobywamy ze słownika
``request.POST`` za pomocą metody ``get('tekst', '')``. Jej pierwszy argument
odpowiada nazwie pola formularza użytej w szablonie, które chcemy odczytać.
Drugi argument oznacza wartość domyślną, przydatną, jeśli
pole będzie niedostępne. Po sprawdzeniu długości wiadomości, możemy
ją utworzyć wykorzystując konstruktor naszego modelu
``Wiadomosc(tekst=tekst, data_pub=timezone.now(), autor=request.user)``.
W formie nazwanych argumentów podajemy mu wartości kolejnych pól.
Zapisanie nowej wiadomości w bazie sprowadza się do polecenia ``wiadomosc.save()``.

Na koniec przekierowujemy użytkownika do tego samego widoku,
ale tym razem jest to żądanie typu :term:`GET`.
W odpowiedzi na nie pobieramy wszystkie wiadomości z bazy (``Wiadomosc.objects.all()``),
i przekazujemy do szablonu, który zwracamy użytkownikowi.

Zadaniem szablonu zapisanego w pliku :file:`~/czat/czat/templates/wiadomosci.html`
jest wyświetlenie komunikatów zwrotnych, formularza dodawania wiadomości
i listy wiadomości dodanych.

.. raw:: html

    <div class="code_no">Plik wiadomosci.html nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: html
.. literalinclude:: wiadomosci_z9.html
    :linenos:

Ćwiczenie 8
=====================

Powiąż widok ``wiadomosci()`` z adresem */wiadomosci* w pliku :file:`urls.py`,
nadając mu nazwę *wiadomosci*, a następnie uzupełnij szablon widoku głównego,
aby zalogowanym użytkownikom wyświetlał się link prowadzący do strony z wiadomościami.
W szablonie ``wiadomosci.html`` dodaj link do strony głównej i link wylogowania.

.. tip::

    Definicje w pliku :file:`urls.py` sprawdzane są po kolei, zwracany jest
    widok przypisany pierwszemu napotaknemu dopasowaniu adresu. Jeżeli chcemy
    przetestować działanie widoku ``wiadomosci()`` dla wykorzystanego już
    adresu */wiadomosci* przypisanego wbudowanemu widokowi ListView, powiązanie
    należy umieścić przed nim, np. na początku.

Zaloguj się i przetestuj wyświetlanie [#]_ i dodawanie wiadomości pod adresem
*127.0.0.1:8000/wiadomosci/*. Sprawdź, co się stanie po wysłaniu pustej
wiadomości.

.. [#] Jeżeli nie dodałeś do tej pory żadnej wiadomości, lista na początku
   będzie pusta.

Poniższe zrzuty prezentują efekty naszej pracy:

.. figure:: img/czat21wiadomosci.png


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
