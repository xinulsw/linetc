Toto Lotek
##############

W Toto Lotku trzeba zgadywać liczby. Napiszmy prosty program, w którym
będziemy mieli podobne zadanie. Użyjemy języka Python.

.. contents::
    :depth: 1
    :local:

Mały Lotek
**************

Zaczynamy od utworzenia pliku o nazwie :file:`toto.py` w dowolnym katalogu
za pomocą dowolnego edytora, np. :ref:`Geany <geany-opis>`. Zapis ``~$`` poniżej oznacza katalog
domowy użytkownika. Obowiązkowa zawartość pliku:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto01.py
    :linenos:

Pierwsza linia to ścieżka do interpretera Pythona (zob. :term:`interpreter`),
druga linia deklaruje sposób kodowania znaków, dzięki czemu możemy używać
polskich znaków.

Losowanie liczby
*****************

Musimy wylosować liczby, ale zaczniemy od jednej. Potrzebujemy funkcji
``randint(a, b)`` z modułu ``random``. Zwróci nam ona liczbę całkowitą
z zakresu <a; b>. Do naszego pliku dopisujemy:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto02.py
    :linenos:
    :emphasize-lines: 4, 6-7
    :lineno-start: 1
    :lines: 1-

Wylosowana liczba zostanie zapamiętana w **zmiennej** ``liczba`` (zob. :term:`zmienna` ).
Instrukcja ``print`` wydrukuje ją razem z komunikatem na ekranie.
Program możemy już uruchomić w terminalu (zob. :term:`terminal`),
wydając w katalogu z plikiem polecenie:

.. code-block:: bash

    ~$ python toto.py

Efekt działania naszego skryptu:

.. figure:: img/toto02.png

Zgadywanie
***********

Liczbę mamy, niech gracz, czyli użytkownik ją zgadnie. Pytanie tylko,
na ile prób mu pozwolimy. Zacznijmy od jednej! Dopisujemy zatem:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto03.py
    :linenos:
    :emphasize-lines: 7, 9
    :lineno-start: 1
    :lines: 1-

Na początku **zakomentowujemy** znakiem ``#`` instrukcję drukującą wylosowaną liczbę.
Nie będzie wykonywana :-) Liczbę podaną przez użytkownika pobieramy za pomocą
instrukcji ``raw_input()`` i zapamiętujemy w zmiennej ``odp``.

.. attention::

    Zakładamy na razie, że gracz wprowadza poprawne dane, czyli liczby
    całkowite!

Ćwiczenie 1
=============

Dopisz odpowiednie polecenie, które wyświetli liczbę podaną przez gracza.
Przetestuj jego działanie.

.. figure:: img/toto03.png

Sprawdzanie
**************

Mamy wylosowaną liczbę i typ gracza, musimy sprawdzić, czy trafił.
Uzupełniamy nasz program:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto04.py
    :linenos:
    :emphasize-lines: 12-15
    :lineno-start: 1
    :lines: 1-

Używamy **instrukcji warunkowej** ``if``, która sprawdza prawdziwość warunku
``liczba == int(odp)`` (zob. :term:`instrukcja warunkowa`).
Jeżeli wylosowana i podana liczba są sobie równe (``==``),
wyświetlamy informację o wygranej, w przeciwnym razie (``else:``) zachętę
do ponownej próby. Dodatkowa funkcja ``int()`` zamienia podaną przez
gracza wartość na liczbę całkowitą.

.. note::

    Instrukcja ``raw_input()`` wszystkie pobrane dane zwraca jako tekst,
    dlatego jeżeli wprowadzone wartości chcemy wykorzystywać jako liczby,
    musimy używać funkcji ``int()``, która próbuje podany tekst
    przekształcić na typ całkowity (*integer*). Jeżeli nie jest w stanie
    tego zrobić, zgłasza wyjątek ``ValueError``. Ich obsługę omówimy
    później.

Przetestuj kilkukrotnie działanie programu.

.. figure:: img/toto04.png

Do 3 razy sztuka
*****************

Trafienie za pierwszym razem wylosowanej liczby jest bardzo trudne, spróbujmy
dać graczowi 3 szanse. Zmieniamy i uzupełniamy kod:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto05.py
    :linenos:
    :emphasize-lines: 9
    :lineno-start: 1
    :lines: 1-

Pobieranie i sprawdzanie kolejnych liczb wymaga powórzenia zakodowanych
wcześniej operacji. Do tego celu używamy **pętli** ``for`` (zob. :term:`pętla`).
Umieszczamy w niej blok poprzednio napisanego kodu odpowiednio
wcięty (zob. :term:`formatowanie kodu`).

Ilość powtórzeń określa wyrażenie ``i in range(3)``. **Zmienna iteracyjna** ``i``
to "licznik" powtórzeń. Będzie się on zmieniał tyle razy, ile wartości
zwróci funkcja ``range(n)``. Funkcja ta generuje listę liczb całkowitych
od *0* do *n-1*.

Ćwiczenie 2
=============

Zamiast się domyślać, sprawdźmy działanie omawianej funkcji w trybie interaktywnym
interpretera Pythona. W terminalu wpisz polecenia:

.. code-block:: python

    ~$ python
    >>> range(3)
    >>> for i in range(3)
    ...   print i
    ...
    >>> exit()

Jak wynika z powyższego, zmienna ``i`` przyjmie wartość 0, 1 i 2, czyli
pętla ``for`` wykona się 3 razy. Wszystkie polecenia znajdujące się wewnątrz
pętli również 3 razy, chyba że... Właśnie, a jeżeli użytkownik trafi
za 1 lub 2 razem? Wtedy warunek w instrukcji ``if`` stanie się prawdziwy,
wyświetli się informacja o nagrodzie, a polecenie ``break`` przerwie działanie
pętli. Przetestuj działanie programu, ale wcześniej przeczytaj jeszcze poniższą
uwagę:

.. note::

    W kodzie Pythona bardzo ważną rolę pełnią wcięcia. W obrębie całego pliku
    muszą one być równe (najczęściej 4 spacje i ich wielokrotności),
    służą bowiem wydzielaniu bloków kodu. Wskazują więc, które polecenia,
    którym są podporządkowane. W naszym przypadku linie 10, 13 i 16
    muszą mieć wcięcia pojedyncze (np. 4 spacje), a linie 14-15, 17-18
    podwójne (np. 8 spacji). Inaczej pojawią się błędy ``IndentationError``.

Ćwiczenie 3
=============

Uzupełnij kod, tak aby program wyświetlał informację "Próba 1", "Próba 2"
itd. przed podaniem liczby. **Wskazówki**: Wykorzystaj zmienną ``i`` i
sprawdź również w trybie interaktywnym, co się dzieje, kiedy wpiszesz:

.. code-block:: bash

    ~$ python
    >>> i = 0
    >>> print i
    >>> i = i + 1
    >>> print i

Ćwiczenie 4
=============

Po 3 błędnej próbie program ponownie wyświetla komunikat: "Nie zgadłeś...
Spróbuj jeszcze raz." Użyj intrukcji ``if`` z odpowiednim warunkiem
i wcięciami (!), aby po 3 nieudanej próbie wyświetlić komunikat:
"Miałem na myśli liczbę: liczba".

Ostateczny wynik działania naszego programu prezentuje się tak:

.. figure:: img/toto07.png

Duży Lotek
************

Jedna liczba to za mało, wylosujmy ich więcej! Zasady dużego lotka to typowanie
6 liczb z 49. Ponieważ trafienie jest tu bardzo trudne, napiszemy program
w taki sposób, aby można było łatwo dostosować poziom jego trudności.
Na początku utwórz nowy plik :file:`toto2.py` i uzupełnij go wymaganymi
liniami wskazujacymi interpreter pythona i użyte kodowanie.

Ćwiczenie 5
=============

Niech użytkownik określi ile liczb chce typować i z jakiego zakresu.
Pobierz od użytkownika ilość typowanych liczb, podaną wartość przechowaj
w zmiennej ``ileliczb``. Podobnie pobierz i zapisz maksymalną losowaną liczbę
w zmiennej ``maksliczba``. Na koniec wyświetl komunikat "Wytypuj x z y liczb: ".
Zamiast *x* i *y* powinny wyświetlić się podane przez użytkownika wartości.

.. tip::

    Skorzystaj z instrukcji ``raw_iput()``, której użyj jako argumentu
    funkcji ``int()``.

Losowanie wielu liczb
*********************

Ćwiczenie 6
=============

Jedną wylosowaną liczbę zapamiętywaliśmy w jednej zmiennej, ale przechowywanie
wielu wartości w osobnych zmiennych nie jest dobrym pomysłem. Najwygodniej
byłoby mieć jedną zmienną, w której można zapisać wiele wartości. W Pythonie
takim złożonym typem danych jest :term:`lista`.

Przetestuj w interpreterze następujące polecenia:

.. code-block:: bash

    ~$ python
    >>> liczby = []
    >>> liczby
    >>> liczby.append(1)
    >>> liczby.append(2)
    >>> liczby.append(4)
    >>> liczby.append(4)
    >>> liczby
    >>> liczby.count(1)
    >>> liczby.count(4)
    >>> liczby.count(0)

.. tip::

    Zamiast wpisywać w terminalu powtarzające się lub podobne polecenia,
    użyj klawiszy kursora (góra, dół) do przywoływania poprzednich
    poleceń. Każde przywołane polecenie możesz przed zatwierdzeniem
    zmienić używając klawiszy lewo, prawo, del i backspace.

Jak widać po zadeklarowaniu pustej listy (``liczby = []``), metoda ``.append()``
pozwala dodawać do niej wartości, a metoda ``.count()`` podaje, ile razy
dana wartość wystąpiła w liście. To się nam przyda ;-)

Wróćmy do programu i pliku :file:`toto2.py`. Losowanie wielu liczb to...
powtarzające się losowanie jednej liczby, czyli pętla. Spróbuj użyć poznanej
wcześniej instrukcji ``for``, aby dopisać kod losujący ``ileliczb``
z zakresu ograniczonego przez ``maksliczba``. Wylosowane wartości wydrukuj
w terminalu... Przetestuj program, powinien wypisywać kolejne losowane
liczby.

Kontynuujemy ćwiczenie. Przed pętlą zadeklaruj pustą listę. Wewnątrz pętli
umieść polecenie dodające wylosowane liczby do listy. Na końcu programu
(uwaga na wcięcia) wydrukuj zawartość listy. Wielokrotnie przetestuj program;
czy lista zawsze zawiera akceptowalne wartości?

.. figure:: img/toto22_0.png

Pętla ``for`` nie nadaje się do losowania liczb, ponieważ wykonuje się określoną ilość razy,
a nie możemy zagwarantować, że losowane liczby będą za każdym razem inne.
Do wylosowania podanej ilości liczb wykorzystamy więc pętlę ``while wyrażenie_logiczne:``,
która powtarza kod dopóki podane wyrażenie jest prawdziwe.
Uzupełniamy Kod w pliku :file:`toto2.py`:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto22.py
    :linenos:
    :emphasize-lines: 10-19
    :lineno-start: 1
    :lines: 1-

Losowane liczby zapamiętujemy w **liście** ``liczby`` (zob. :term:`lista`).
Zmienna ``i`` to licznik unikalnych wylosowanych liczb, korzystamy z niej w wyrażeniu
warunkowym ``i < ileliczb``, które kontroluje powtórzenia pętli. W instrukcji
warunkowej wykorzystujemy funkcję zliczającą wystąpienia wylosowanej wartości
w liście (``liczby.count(liczba)``), aby dodawać (``liczby.append(liczba)``)
do listy liczby wcześniej niepodane.

Nasze typy
***********

Przy pobieraniu typów użytkownika użyjemy podobnie jak przed chwilą pętli
``while``, ale typy zapisywać będziemy w zbiorze, który z założenia nie
może zawierać duplikatów (zob. :term:`zbiór`).

Ćwiczenie 7
=============

W interpreterze Pythona przetestuj następujące polecenia:

.. code-block:: bash

    ~$ python
    >>> typy = set()
    >>> typy.add(1)
    >>> typy.add(2)
    >>> typy
    >>> typy.add(2)
    >>> typy
    >>> typy.add(0)
    >>> typy.add(9)
    >>> typy

Pierwsza instrukcja deklaruje pusty zbiór (``typy = set()``). Metoda ``.add()``
dodaje do zbioru elementy, ale nie da się dodać dwóch takich samych elementów.
Drugą cechą zbiorów jest to, że ich elementy nie są w żaden sposób uporządkowane.

Wykorzystajmy poznany typ, aby pobrać od użytkownika typy liczb. W pliku
:file:`toto2.py` dopisujemy:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto23.py
    :linenos:
    :lineno-start: 20
    :lines: 20-27

W powyższym kodzie warto zwrócić na sposób sprawdzania, czy podana liczba
nie została już w zbiorze umieszczona: ``if typ not in typy:``. Gdybyśmy
chcieli sprawdzić, czy liczba jest w zbiorze, użylibyśmy wyrażenia ``typ in typy``.
Przetestuj rogram.

Ile trafiliśmy
***************

Określenie ilości trafień w większości języków programowania wymagałoby
przeszukiwania listy wylosowanych liczb dla każdego podanego typu. W Pythonie
możemy użyć arytmetyki zbiorów: wyznaczymy część wspólną.

Ćwiczenie 8
==============

W interpreterze przetestuj poniższe instrukcje:

.. code-block:: bash

    ~$ python
    >>> liczby = [1,3,5,7,9]
    >>> typy = set([2,3,4,5,6])
    >>> set(liczby) | typy
    >>> set(liczby) - typy
    >>> trafione = set(liczby) & typy
    >>> len(trafione)

Polecenie ``set(liczby)`` przekształca listę na zbiór. Kolejne operatory
zwracają sumę (``|``), różnicę (``-``) i iloczyn (``&``), czyli część
wspólną zbiorów. Ta ostania operacja bardzo dobrze nadaje się do sprawdzenia,
ile liczb trafił użytkownik. Funkcja ``len()`` zwraca ilość elementów m.in.
listy i zbioru.

Do pliku :file:`toto2.py` dopisujemy:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto24.py
    :linenos:
    :lineno-start: 31
    :lines: 31-36

Instrukcja ``if trafione:`` sprawdza, czy część wspólna zawiera jakiekolwiek elementy.
Jeśli tak, drukujemy liczbę trafień i trafione liczby.

Ćwiczenie 9
==============

Przetestuj program dla 5 typów z 10 liczb. Działa?
Jeśli masz wątpliwości, wpisz wylosowane i wytypowane liczby w interpreterze,
np.:

.. code-block:: bash

    >>> liczby = [1,4,2,6,7]
    >>> typy = set([1,2,3,4,5])
    >>> trafione = set(liczby) & typy
    >>> if trafione:
    ...   print len(trafione)
    ...
    >>> print trafione

Wnioski? Logika kodu jest poprawna, czego dowodzi test w terminalu, ale
program nie działa. Dlaczego?

.. tip::

    Przypomnij sobie, jakiego typu wartości zwraca funkcja ``raw_input()``.

Ćwiczenie 10
==============

Zmodyfikuj program tak, aby wynik jegzo działania wyglądał następująco:

.. figure:: img/toto25.png

Ćwiczenie 11
==============

Zmień program tak, aby użytkownik mógł 3 razy typować liczby z tej
samej serii liczb wylosowanych. Wynik działania programu powinien przypominać
poniższy zrzut:

.. figure:: img/toto26.png

.. tip::

    Wykorzystaj pętlę ``for``.

Uwaga: błędne dane!
*******************

Kod naszego programu do tej pory przedstawia się mniej więcej tak:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto26.py
    :linenos:

Uruchom powyższy program i podaj ilość losowanych liczb większą od maksymalnej losowanej liczby.
Program wpada w nieskończoną pętlę! Po chwili zastanowienia dojdziemy
do wniosku, że nie da się wylosować np. 6 unikalnych liczb z zakresu 1-5.

Ćwiczenie 12
=============

Dodaj odpowiednią instrukcję warunkową, która w przypadku gdy zmienna ``ileliczb``
będzie mniejsza od zmiennej ``maksliczba`` wyświetli komunikat "Błędne dane!"
i przerwie wykonywanie programu – użyj funkcji ``exit()``. Sprawdź działanie programu.


Tetsujemy dalej. Uruchom program i zamiast liczby podaj tekst.
Co się dzieje?

Zgłoszony zostaje wyjątek "ValuError" (zob.: :term:`wyjątki`) i komunikat
"invalid literal for int() with base 10", który informuje, że fukncja ``int()``
nie jest w stanie przekształcić podanego ciągu znaków na liczbę całkowitą.

Spróbujmy zmodyfikować program tak, aby był nieco odporniejszy na niepoprawne dane:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto28.py
    :linenos:
    :lineno-start: 6
    :lines: 6-14

Do przechwytywania wyjątków używamy konstrukcji ``try: ... except: ...``, czyli
spróbuj wykonać kod w bloku ``try``, a w razie błędów przechwyć wyjątek ``ValueError``
i wykonaj podporządkowane instrukcje. W powyższym przypadku wyświetlamy odpowiedni
komunikat i kończymy działanie programu (``exit()``).

Przetestuj program wprowadzając tekst zamiast liczb.

Ćwiczenie 13
=============

Program powinien być odporny na błędne dane we wszystkich miejscach, w których
pobiera dane od użytkownika. Wprowadź konieczne poprawki kodu i przetestuj
swoje rozwiązania.

.. tip::

    Problemem może być pobieranie typów od użytkownika. Nie dość, że użytkownik
    może wpisać literę zamiast cyfry, to jeszcze podane liczby mogą być poza zakresem.

    Trzeba więc użyć konstrukcji ``try... except...``. Ale co powinno się stać,
    jeśli użytkownik poda błędne dane? Przerwanie programu, jak wcześniej,
    nie jest najlepszym pomysłem. Lepiej użyć polecenia ``continue``, które
    pomija dalszy kod, ale kontynuuje wykonywanie pętli.

    Trzeba również dodać odpowiednie warunki sprawdzające porawność podanych liczb.
    Wyrażenia logiczne można umieścić wykorzystując operator logiczny ``and``
    w warunku sprawdzającym, czy wylosowanej liczby nie ma w zbiorze.

Funkcje i moduły
*****************

Tam, gdzie w programie występują powtarzające się operacje lub zestaw poleceń
realizujący wyodrębnione zadanie, wskazane jest używanie funkcji.
Są to nazwane bloki kodu, które można grupować w ramach modułów (zob. :term:`funkcja`, zob. :term:`moduł`).
Funkcje zawarte w modułach można importować do różnych programów.
Do tej pory korzystaliśmy np. z funkcji ``randit()`` zawartej w module ``random``.

Wyodrębnienie funkcji ułatwia sprawdzanie i poprawianie kodu, ponieważ
wymusza podział programu na logicznie uporządkowane kroki. Jeżeli
program korzysta z niewelu funkcji, można umieszczać je na początku pliku
programu głównego.

Tworzymy więc nowy plik :file:`totomodul.py` rozpoczynający się liniami wskazującymi
interpreter i kodowanie. Umieszczamy w nim następujący kod:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: totomodul30.py
    :linenos:
    :emphasize-lines: 6, 9, 17, 22, 31, 34, 49

Kod odpowiedzialny za ustawienia gry, losowanie liczb i pobieranie typów
użytkownika umieszczony został w osobnych funkcjach sygnalizowanych słowem
kluczowym ``def`` i wcięciami. Funkcje mogą przyjmować definiowane w nawiasach
dane wejściowe, np. ``losujliczby(ile, maks)``, które podajemy jako argumenty
w momencie wywołania funkcji. Funkcje mogą zwracać dane wyjściowe za pomocą
instrukcji ``return``.

Warto zauważyć, że można zwracać więcej niż jedną wartość naraz,
np. w postaci tupli ``(ile, maks, ilelos)``. Tupla to rodzaj listy, w której
nie możemy zmieniać wartości (zob. :term:`tupla`), jest często stosowana
do przechowywania i przekazywania stałych danych.

Nazwy zmiennych lokalnych w funkcjach są niezależne od nazw zmiennych w programie
głównym, ponieważ definiwane są w różnych zasięgach czy też przestrzeniach nazw.
Możliwe jest tworzenie zmiennych globalnych dostępnych w całym programie,
w funkcji odwołujemy się do nich za pomocą polecenia typu: ``global nazwa_zmiennej``.

Wiele wartości zwracanych w tupli przez funkcję ``ustawienia()`` można
jednocześnie przypisać kilku zmiennym dzięki operacji tzw. rozpakowania
tupli: ``ileliczb, maksliczba, ilerazy = ustawienia()``.

Dwie pozostałe funkcje zwracają listę wylosowanych liczb i zbiór typów.

Program główny po zmianach przedstawia się następująco:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto30.py
    :linenos:
    :emphasize-lines: 4, 9, 12, 16

Na początku z modułu ``totomodul``, którego nazwa jest taka sama jak nazwa pliku,
importujemy potrzebne funkcje. Później wywołujemy je podając nazwę i ewentualne
argumenty. W efekcie zwracane przez nie wartości zostają przypisane podanym zmiennym.
Jak widać, program stał się czytelniejszy.

.. note::

    W rozbudowanych programach dobrą praktyką ułatwiającą późniejsze przeglądanie
    i poprawianie kodu jest opatrywanie jego fragmentów komentarzami. Można je
    umieszczać po znaku ``#``. Z kolei funkcje opatruje się krótkim opisem
    działania i/lub wymaganych argumentów, ograniczanym potrójnymi cudzysłowami.
    Notacja ``"""..."""`` lub ``'''...'''`` pozwala zamieszczać teksty wielowierszowe.

Historia losowań
****************

Uruchamiając wielokrotnie program, moglibyśmy zapamiętywać losowania
użytkownika, tworząc rejestr do celów informacyjnych i/lub statystycznych.
Zadanie wymaga po pierwsez zdefiniowania jakieś struktury, w której będziemy
przechowywali dane, po drugie zaś zapisu danych np. na dysku albo w plikach,
albo w bazie danych.

Na początku dopiszemy kod w programie głównym :file:`toto2.py`:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto31.py
    :linenos:
    :emphasize-lines: 34-39
    :lineno-start: 28
    :lines: 28-

Dane graczy zapisywać będziemy w osobnych plikach nazywanych nickiem
użytkownika z rozszerzeniem ".json": ``nazwapliku = nick + ".json"``.
Informacje o grach przechowywać będziemy w liście ``losowania``,
do której próbujemy na początku wczytać zapisane ewentualnie wcześniej
dane: ``losowania = czytaj(nazwapliku)``.

Elementami listy danych są natomiast słowniki, tzn. dane pogrupowane w parach
"klucz: wartość", przy czym kluczami mogą być nie tylko liczby, ale również
ciągi znakowe (zob. :term:`słownik`).

Jak widać, do listy ``losowania`` dodajemy słownik zawierający datę (nie
zapomnijmy dodać importu modułu ``time``!), ustawienia, wylosowane liczby
oraz ilość trafień. Na końcu listę wszystkich losowań gracza zapisujemy
do pliku.

Teraz zobaczmy, jak wyglądają funkcje ``czytaj()`` i ``zapisz()`` w module
:file:`totomodul31.py`:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: totomodul31.py
    :linenos:
    :lineno-start: 51
    :lines: 51-

Kiedy czytamy i zapisujemy dane, ważną sprawą staje się ich format. Najprościej
zapisywać dane jako znaki, jednak najczęściej programy użytkowe
potrzebują zapisywać nie tyle teksty, ile złożone struktury danych, np.
listy, zbiory czy słowniki. Znakowy zapis wymagałby wtedy wielu dodatkowych
manipulacji, aby możliwe było poprawne odtworzenie informacji. Prościej
jest skorzystać z serializacji, czyli zapisu danych obiektowych (zob. :term:`serializacja`).
Jednym z szerzej stosowanych jest prosty format tekstowy :term:`JSON`.

W funkcji ``czytaj()`` po sprawdzeniu, czy na dysku istnieje podany plik,
otwieramy go w trybie odczytu ``"r"`` i jego zawartość dekodujemy do
listy dane: ``dane = json.load(plik)``.

Funkcja ``zapisz()`` oprócz nazwy pliku wymaga listy danych. Po otwarciu
pliku w trybie zapisu ``plik = open(nazwapliku, "w")``, co powoduje wyczyszczenie
jego zawartości, dane są serializowane i zapisywane formacie JSON:
``json.dump(dane, plik)``.

Dobrą praktyką jest zwalnianie uchwytu do pliku i przyddzielonych mu zasobów
poprzez jego zamknięcie: ``plik.close()``.

Przetestuj, przynajmniej kilkukrotnie, działanie programu.

Ćwiczenie 14
=============

W programie w pętli ``for`` wielokrotnie powtarzać się może obliczanie
ilości trafień i drukowanie komunikatów. Spróbuj utworzyć funkcję ``wyniki()``
realizującą te operacje. Funkcję umieść w module programu, a następnie
użyj jej w pętli. Zastanów się, jakie argumenty należy jej przekazać i co
powinna zwracać.

.. tip::

    Zwróć uwagę, jakie dalsze operacje są zależne od zastępowanego kodu.

Wydruk historii
****************

[todo]

.. raw:: html

    <hr />

Jeżli masz ochotę na więcej, daj znać!
