.. _klocki01:

*Gra robotów* – klocki 1
####################################

Środowisko testowe
*******************

Do budowania i testowania robotów używamy pakietu *rgkit*. W tym celu
przygotowujemy środowisko deweloperskie w katalogu :file:`robot`,
zawierające bibliotekę ``rg``. W terminalu wydajemy polecenia:

.. code-block:: bash

    ~$ mkdir robot; cd robot
    ~robot$ virtualenv env
    ~robot$ source env/bin/activate
    (env):~/robot$ pip install rgkit

Dodatkowo instalujemy pakiet zawierający roboty open source, następnie symulator
ułatwiający testowanie, a na koniec tworzymy skrót do jego uruchamiania:

.. code-block:: bash

    (env):~/robot$ git clone https://github.com/mpeterv/robotgame-bots bots
    (env):~/robot$ git clone https://github.com/mpeterv/rgsimulator.git
    (env):~/robot$ ln -s rgsimulator/rgsimulator.py symuluj

Po wykonaniu wszystkich powyższych poleceń i wykonaniu komendy ``ls -l``
powinniśmy zobaczyć:

.. figure:: img/rgkit_env.png

Kolejne wersje robota będziemy zapisywać w plikach *robot01.py*, *robot02.py*
itd. Zapisane roboty można uruchamiać lub testować za pomocą poleceń:

.. code-block:: bash

    (env)~/robot$ rgrun robot01.py robot02.py
    (env)~/robot$ rgrun bots/stupid26.py robot01.py
    (env)~/robot$ ./symuluj robot01.py robot02.py

Symulatorem sterujemy za pomocą klawiszy:

* Klawisz F: utworzenie robota-przyjaciela w zaznaczonym polu.
* Klawisz E: utworzenie robota-wroga w zaznaczonym polu.
* Klawisze Delete or Backspace: usunięcie robota z zaznaczonego pola.
* Klawisz H: zmiana punktów HP robota.
* Klawisz C: wyczyszczenie planszy gry.
* Klawisz Spacja: pokazuje planowane ruchy robotów.
* Klawisz Enter: uruchomienie rundy.
* Klawisz G: tworzy i usuwa roboty w punktach wejścia (ang. *spawn locations*), "generowanie robotów".

.. attention::

    Pokazana powyżej instalacja zakłada użycie środowiska wirtualnego tworzonego
    przez pakiet *virtualenv*, dlatego przed uruchomieniem rozgrywki
    lub symulacji trzeba pamiętać o wydaniu w katalogu :file:`robot` polecenia
    ``source env/bin/activate``. Poleceniem ``deactivate`` opuszczamy
    środowisko wirtualne.

Sztuczna inteligencja
**********************

Tworzenie sztucznej inteligencji robota można sprowadzić do odpowiedzi na
pytanie, według jakich zasad ma działać robot w określonych sytuacjach.
Na podstawie odpowiedzi określamy regułę zachowania, implementujemy ją
i testujemy, np.:

1) Gdzie ma iść robot po po wejściu na arenę?
2) Odpowiedź, czyli reguła AI, np.: "Idź do środka".
3) Jaki kod umożliwi robotowi realizowanie tej reguły?
4) Czy to działa?

Poniżej przedstawiamy kilka reguł i realizującego je kodu. Zadaniem
gracza jest ustalić, kiedy robot ma podjąć dane działanie i w jakiej kolejności.
Składając te "klocki", gracz tworzy strategię działania robota.

.. tip::

    * Każdy "klocek" można testować osobno, a później w połączeniu z innymi.
      Warto i trzeba zmieniać kolejność stosowanych reguł!

Idź do środka
**************

To będzie nasza domyślna reguła. Umieszczamy ją w pliku :file:`robot01.py`
zawierającym niezbędne minimum działającego bota:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod01.py
   :linenos:

W środku broń się lub giń
**************************

Co powinien robić robot, kiedy dojdzie do środka? Może się bronić lub
popełnić samobójstwo:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod02.py
    :linenos:

Atakuj wrogów obok
*******************

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

Robot podstawowy
*****************

Łącząc omówione wyżej trzy podstawowe reguły, otrzymujemy podstawowego robota:

.. raw:: html

    <div class="code_no">Plik robot01.py. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: robot01.py
    :linenos:

Wybrane działanie robota zwracamy za pomocą instrukcji ``return``.
Bardzo ważna jest tu kolejność umieszczenia reguł, pierwszy spełniony warunek
powoduje bowiem wyjście z funkcji, pozostałe możliwości nie są już sprawdzane.

.. raw:: html

    <hr />

W miarę rozbudowywania robota przydatniejsze będzie podejście niejako odwrotne.
Zainicjujemy zmienną pomocniczą ``ruch`` działaniem domyślnym, które w kolejnych
regułach będzie można zmienić. Dopiero na końcu zwrócimy ustaloną akcję.
Kod przyjmie następującą postać:

.. raw:: html

    <div class="code_no">Plik robot02.py. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: robot02.py
    :linenos:
    :emphasize-lines: 5, 8, 13,15
    :lineno-start: 6
    :lines: 6-

Ćwiczenie 1
=============

Przetestuj działanie robota podstawowego wystawiając go do gry z samym sobą
w symulatorze. Zaobserwuj zachowanie się robotów:

.. code-block:: bash

    (env)~/robot$ python ./symuluj robot02.py robot02.py

Zbiory pól
***********

Zmieńmy podejście. Sprawdzanie wszystkich położeń w poszukiwaniu wrogów
lub członków drużyny wymaga korzystania z pętli przeglądającej słownik
``robot.game``. Można użyć zbiorów (zob. :term:`zbiór`) tworzonych za pomocą
wyrażeń listowych (zob. :term:`wyrażenie listowe`), aby wyznaczyć pola
zajmowane przez określone roboty.

Poniższy kod wstawiamy na początku metody ``Robot.act()``:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgzbiory.py
    :linenos:

Metoda ``rg.loc_types()`` z biblioteki *rg* ułatwia nam zadanie,
zwraca typ położenia wskazywanego przez podane współrzędne, np.
instrukcja warunkowa ``if 'spawn' in rg.loc_types(poz)`` sprawdza,
czy badane położenie ``poz`` jest punktem wejścia.

.. raw:: html

    <hr />

Zapiszy dotychczasowy kod w pliku :file:`robot03.py`, definicje zbiorów
umieść na początku metody ``Robot.act()``. Zdefiniowane zbiory wykorzystamy
w określaniu reguł zachowania robota.

Opuść wejście
**************

Po instrukcji określającej akcję domyślną umieść kod:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod04.py
    :linenos:

Atakuj, jeśli nie umrzesz
**************************

Warto atakować, ale nie wtedy, gdy grozi nam śmierć.
Zamień dotychczasowy kod atakujący wroga obok na następujący:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod05.py
    :linenos:

.. tip::

    Wyrażenia tworzące zbiory (również nowe) trzymaj w kodzie razem.

W sumie powinnieneś uzyskać następujący kod robota:

.. raw:: html

    <div class="code_no">Plik robot03.py. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: robot03.py
    :linenos:

Atakuj na 2 kroki
*******************

Dotychczasowy kod zapisz w pliku
:file:`robot04.py` i dodaj do niego nową regułę.

Jeżeli w odległości 2 kroków jest przeciwnik, lepiej zaatakuj.

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod06.py
    :linenos:

.. raw:: html

    <hr />

Do środka bezpiecznie i szybko
*******************************

Dotychczasowy kod zapisz w pliku :file:`robot05.py` i wprowadź omawiane zmiany.
Zamiast iść na oślep lepiej szybko i bezpiecznie iść do celu.
Wyznaczamy więc zbiór sąsiednich pól, na które można bezpiecznie
wejść. Następnie definiujemy funkcję zwracającą pole, na które należy wejść,
aby dostać się do celu jak najszybciej. Na koniec zmieniamy kod nakazujący
robotowi opuszczać punkt wejścia.

.. raw:: html

    <div class="code_no">Plik robot05.py. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: robot05.py
    :linenos:
    :emphasize-lines: 1, 3-4, 10-11
    :lines: 18-28

.. raw:: html

    <hr />

Idź na najbliższego wroga
*************************

W pliku :file:`robot06.py` dodamy jeszcze jedną regułę. Funkcję ``mindist()``
można użyć do znalezienia najbliższego wroga, aby iść w jego kierunku,
gdy opuścimy punkt wejścia:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod08.py
    :linenos:

Możę się zdarzyć, że nie będzie można bezpiecznie się ruszyć, wtedy pozostaje
obrona jako działanie domyślne.

Mamy robota
*************

Po złożeniu wszystkich powyższych klocków budowany dotychczas robot może przedstawiać się następująco:

.. raw:: html

    <div class="code_no">Plik robot06.py. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: robot06.py
    :linenos:

Jeżeli wystawisz go do walki np. z robotem 2, okaże się, że jest od niego gorszy!
Jak myślisz, dlaczego? Spróbujmy go poprawić: usuń regułę mówiącą, żeby
robot bronił się w środku – jest niepotrzebna, jeśli domyślną akcją jest obrona.
Zmień również niezależne funkcje warunkowe w łańcuch decyzyjny ``if...elif...else...``.
Poprawiony kod będzie wyglądał tak:


.. raw:: html

    <div class="code_no">Plik robot07.py. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: robot07.py
    :linenos:

Przetestuj różne wersje robotów. Która radzi sobie najlepiej? Na koniec
uwaga: nie gwarantujemy, że zaproponowana implementacja jest najlepszą możliwą do
złożenia z podanych klocków :-)

.. raw:: html

    <hr />
