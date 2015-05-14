Toto Lotek
##############

W Toto Lotku trzeba zgadywać liczby. Napiszmy prosty program, w którym
będziemy mieli podobne zadanie. Użyjemy języka Python.

.. contents::
    :depth: 1
    :local:

Plik programu
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
druga linia informuje o użytym kodowaniu, dzięki czemu możemy używać
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
Instrukcja ``print`` wydrukuje ją na ekranie (tylko na razie).
Program możemy już uruchomić wydając w katalogu z plikiem polecenie:

.. code-block:: bash

    ~$ python toto.py

.. note::

    **Terminal** to tekstowa powłoka, pozwalająca sterować pracą komputera za
    pomocą poleceń wpisywanych z klawiatury (lub wklejanych ze schowka).
    W systemach Linux często da się go uruchomić skrótem :kbd:`Win+T`
    lub :kbd:`Ctrl+Alt+T`. Jeśli skróty nie działają szukamy w menu start.
    Skrót :kbd:`Ctrl+Shift+T` pozwala otworzyć kolejną kartę terminala,
    w każdej karcie możemy robić coś innego.

    W Geany kod uruchamiamy naciskając klawisz :kbd:`F5`.

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

Mamy wylosowaną liczbę i strzał gracza, musimy sprawdzić, czy trafił.
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
wyświetlamy informację o wygranej, w przeciwnym razie ``else:`` zachętę
do ponownej próby. Dodatkowa funkcja ``int()`` zamienia podaną przez
gracza wartość na liczbę całkowitą.

.. note::

    Instrukcja ``raw_input()`` wszystkie pobrane dane zwraca jako tekst,
    dlatego jeżeli wprowadzone wartości chcemy wykorzystywać jako liczby,
    musimy używać funkcji ``int(tekst)``, która próbuje podany tekst
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
W jej wnętrzu umieszczamy blok poprzednio napisanego kodu odpowiednio
wcięty (zob. :term:`formatowanie kodu` i komentarz niżej).

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
zobacz również w trybie interaktywnym, co się dzieje, kiedy wpiszesz:

.. code-block:: python

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
w zmiennej ``ileliczb``. Podobnie pobierz i zapisz zakres losowanych liczb
w zmiennej ``zakres``. Na koniec wyświetl komunikat "Wytypuj x z y liczb: ".
Zamiast *x* i *y* powinny wyświetlić się podane przez użytkownika wartości.

.. tip::

    Użyj instrukcji ``raw_iput()``.

Losowanie wielu liczb
*********************

Do wylosowania podanej ilości liczb wykorzystamy pętlę ``while wyrażenie_logiczne:``,
która powtarza kod dopóki podane wyrażenie jest prawdziwe. Pętla ``for`` nie
nadaje się do losowania liczb, ponieważ wykonuje się określoną ilość razy,
a nie możemy zagwarantować, że losowane liczby będą za każdym razem inne.
Do pliku :file:`toto2.py` dopisujemy:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto22.py
    :linenos:
    :lineno-start: 10
    :lines: 10-18

Losowane liczby będziemy zapamiętywali w **liście** ``liczby`` (zob. :term:`lista`).
Zmienna ``i`` zlicza unikalne wylosowane liczby, korzystamy z niej w wyrażeniu
warunkowym ``i < ileliczb``, które kontroluje ilość powtórzeń pętli. W instrukcji
warunkowej wykorzystujemy funkcję zliczającą wystąpienia wylosowanej wartości
w liście: ``liczby.count(liczba)``, aby dodawać do listy liczby wcześniej
niepodane: ``liczby.append(liczba)``.

Ćwiczenie 6
==============

Przetestuj w interpreterze Pythona działanie metod ``count()`` i ``apend()``.
Utwórz listę ``liczby = [1, 2, 9, 8, 5, 5 ]``. Spróbuj dołączyć do niej liczby
*3* i *5*, a następnie zlicz ilość ich wystąpień.

Nasze typy
***********

Przy pobieraniu typów użytkownika użyjemy podobnie jak przed chwilą pętli
``while``, ale typy zapisywać będziemy w zbiorze, który z założenia nie
może zawierać duplikatów (zob. :term:`zbiór`):

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto23.py
    :linenos:
    :lineno-start: 20
    :lines: 20-27

W powyższym kodzie warto zwrócić uwagę na tworzenie pustego zbioru ``typy = set()``
oraz na sposób sprawdzania, czy podana liczba nie została już w zbiorze
umieszczona ``if typ not in typy:``. Jak można się domyśleć, gdybyśmy chcieli
sprawdzić czy liczba jest w zbiorze, użylibyśmy wyrażenia ``typ in typy``.
Kolejny element dodajemy do zbioru za pomocą metody ``add()``.

Ile trafiliśmy
***************

Określenie ilości trafień w większości języków programowania wymagałoby
przeszukiwania listy wylosowanych liczb dla każdego podanego typu. W Pythonie
możemy użyć arytmetyki zbiorów: wyznaczymy część wspólną.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto24.py
    :linenos:
    :lineno-start: 31
    :lines: 31-36

Polecenie ``set(liczby)`` przekształca listę na zbiór. Z kolei operator ``&``
pozwala wyznaczyć część wspólną zbiorów. Instrukcja ``if trafione:`` sprawdza,
czy nowy zbiór zawiera jakiekolwiek elementy. Jeśli tak, drukujemy liczbę
trafień i trafione liczby. Zapamiętajmy, że ilość elementów zbioru czy listy
zwraca funkcja ``len()``.

Ćwiczenie 7
==============

Przetestuj program dla liczby 5 typów z 10 losowanych liczb. Działa?
Jeśli masz wątpliwości, wpisz wylosowane i wtypowane liczby w interpreterze,
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

Ćwiczenie 7
==============

Zmodyfikuj program tak, aby wynik jegzo działania wyglądał następująco:

.. figure:: img/toto25.png

Ćwiczenie 8
==============

Zmodyfikuj program tak, aby użytkownik mógł 3 razy typować liczby z tej
samej serii liczb wylosowanych. Wynik działania programu powinien przypominać
poniższy zrzut:

.. figure:: img/toto26.png

.. tip::

    Wykorzystaj pętlę ``for``.

Uwaga: błędne dane!
*******************

Kod naszego programu do tej pory:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: toto26.py
    :linenos:

[todo]

Ranking trafień
****************

[todo]

.. raw:: html

    <hr />

Jeżli masz ochotę na więcej, daj znać!

.. include:: gloss_python.rst
