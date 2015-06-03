*Gra robotów* – klocki
####################################

Środowisko testowe przygotowujemy wg dokumentu :ref:`rgkit`.

Tworzenie sztucznej inteligencji robota można sprowadzić do odpowiedzi na
pytanie, według jakich zasad ma działać robot w określonych sytuacjach?
Na podstawie odpowiedzi określamy regułę zachowania, implementujemy ją
i testujemy, np.:

1) Co robot ma robić w sytuacji, gdy... i jaki priorytet ma mieć to działanie?
2) Odpowiedź, czyli reguła AI.
3) Jaki kod umożliwi robotowi realizowanie tej reguły?
4) Czy to działa?

Poniżej przedstawiamy kilka przykładów reguł i realizującego je kodu. Zadaniem
gracza jest odpowiedzieć, kiedy robot ma podjąć dane działanie i w jakiej kolejności.
Składając te "klocki", gracz tworzy strategię działania robota.

.. tip::

    * Każdy "klocek" można testować osobno, a później w połączeniu z innymi.
      Warto i trzeba zmieniać kolejność stosowanych reguł!
    * Kolejne wersje robota zapisujemy w osobnych plikach w katalogu :file:`robot`, np.:
      :file:`robot01.py`, :file:`robot02.py`, ...
    * Do "sparingów" :-) można wystawić robota przeciwko samemu sobie, przeciwko
      kolejnej wersji lub konfrontować go z botami open source.
    * Warto korzystać z symulatora!

.. code-block:: bash

    (env)~/robot$ rgrun robot01.py robot01.py
    (env)~/robot$ rgrun robot01.py robot02.py
    (env)~/robot$ rgrun bots/stupid26.py robot01.py

Aby rozpocząć, wydajemy w terminalu polecenia:

.. code-block:: bash

    ~$ cd robot
    ~/robot$ source env/bin/activate

.. raw:: html

    <hr />

Robot podstawowy
*****************

Idź do środka
==============

To będzie nasza domyślna reguła. Umieszczamy ją w pliku :file:`robot01.py`
zawierającym niezbędne minimum działającego bota:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod01.py
   :linenos:

W środku broń się lub giń
==========================

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod02.py
    :linenos:

Atakuj przeciwników obok
===========================

Wersja wykorzystująca pętlę.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod03.py
    :linenos:

Informacje o każdym robocie wydobywane są ze słownika ``game.robots`` za pomocą
metody ``.iteritems()``, która zwraca indeks ``loc``, czyli tuplę *(x,y)*
oznaczającą położenie robota, oraz słownik ``bot`` opisujący właściwości robota:

* *player_id* – identyfikator gracza, do którego należy robot;
* *hp* – ilość punktów HP robota;
* *location* – tupla (x, y) oznaczająca położenie robota na planszy;
* *robot_id* – identyfikator robota, o ile jest w Twojej drużynie.

Możemy grać
============

Łącząc omówione wyżej trzy podstawowe reguły, otrzymujemy podstawowego robota:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: robot03.py
    :linenos:

W powyższym kodzie warto zwrócić uwagę na sposób zwracania wybranego ruchu
za pomocą instrukcji ``return``. Bardzo ważna jest tu kolejność umieszczenia
reguł, pierwszy spełniony warunek powoduje bowiem wyjście z funkcji,
a pozostałe możliwości nie są już sprawdzane.

W miarę rozbudowywania robota przydatniejsze będzie podejście niejako odwrotne.
Zainicjujemy zmienną pomocniczą ``ruch`` działaniem domyślnym, które w kolejnych
regułach będzie można zmienić. Dopiero na końcu zwrócimy ustaloną akcję.
Kod przyjmie następującą postać:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: robot03a.py
    :linenos:
    :emphasize-lines: 5, 8, 13,15
    :lineno-start: 6
    :lines: 6-

.. raw:: html

    <hr />

Zbiory pól
****************

Zmieńmy podejście. Sprawdzanie wszystkich położeń w poszukiwaniu wrogów
lub członków drużyny wymaga ciągłego korzystania z pętli przeglądającej słownik
``robot.game``. Wygodniej będzie użyć wyrażeń listowych (zob. :term:`wyrażanie listowe`),
zbiorów i operacji na nich (zob. :term:`zbiory`), aby wyznaczyć grupy pól, zajmowane
przez określone roboty.

Poniższy kod wstawiamy na początku metody ``Robot.act()``:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgzbiory.py
    :linenos:

Metoda ``rg.loc_types()`` z biblioteki *rg* ułatwia nam zadanie,
zwraca typ położenia wskazywanego przez podane współrzędne, np.
instrukcja warunkowa ``if 'spawn' in rg.loc_types(loc)`` sprawdza,
czy badane popłożenie ``loc`` jest punktem wejścia.

.. raw:: html

    <hr />

Ćwiczenie 1
============

Następną wersję robota zapisz w kolejnym pliku, wykorzystaj *Kod nr 5* jako
punkt wyjścia. Na początku ``Robot.act()`` umieść wymagane do działania podanych
niżej fragmentów kodu definicje zbiorów pól. Wykorzystaj te fragmenty, aby
dodać regułę nakazującą opuszczanie punktów wejścia oraz zmodyfikuj regułę
ataku wrogów obok tak, aby wykorzystywała zbiory. Przetestuj kod.

Opuść wejście
--------------

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod04.py
    :linenos:

Atakuj obok
--------------

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod05.py
    :linenos:

.. tip::

    Wyrażenia tworzące zbiory (również nowe) trzymaj w kodzie razem.
    Zastanów się na miejscem (kolejnością) umieszczenia powyższych reguł.

.. raw:: html

    <hr />

Atakuj, jeśli nie umrzesz
**************************

Wersja wykorzystująca zbiory pól. Warto atakować, ale nie wtedy, gdy grozi nam śmierć.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod06.py
    :linenos:

.. raw:: html

    <hr />

Atakuj na 2 kroki
**************************

Wersja wykorzystująca zbiory pól.
Jeżeli w odległości 2 kroków jest przeciwnik, atakuj.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod07.py
    :linenos:

.. raw:: html

    <hr />

Bezpieczne pola
****************

Wersja wykorzystująca zbiory pól.
Zbiór sąsiednich pól, na które można wejść bez ryzyka.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod08.py
    :linenos:

.. raw:: html

    <hr />

Najbliżej do celu
*******************

Wersja wykorzystująca zbiory pól.
Funkcja, która z podanego zbioru pól (bots) zwraca pole, na które należy wejść,
aby najszybciej dostać się do celu (loc), np. środka planszy lub wroga.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod09.py
    :linenos:

.. raw:: html

    <hr />

Bezpiecznie do środka
**************************

Wersja wykorzystująca zbiory pól.
Idź z punktu wejścia bezpiecznie do środka.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod10.py
    :linenos:

.. raw:: html

    <hr />

Najbliższy wróg
*****************

Wersja wykorzystująca zbiory. Idź bezpiecznie w kierunku najbliższego wroga.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod11.py
    :linenos:

Śledź wybrane miejsca
**********************

Aby unikać niepotrzebnych kolizji, nie należy wchodzić na wybrane wcześniej
pola.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod12.py
    :linenos:

.. raw:: html

    <hr />
