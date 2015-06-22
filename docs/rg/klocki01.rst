.. _klocki01:

*RG* – klocki 1
################

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

**Metody i właściwości biblioteki** *rg*:

* ``rg.toward(poz_wyj, poz_cel)`` – zwraca następne położenie na drodze z bieżącego miejsca do podanego.
* ``self.location`` – pozycja robota, który podejmuje działanie (``self``).
* ``rg.CENTER_POINT`` – środek areny.

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

**Metody i właściwości biblioteki** *rg*:

* Słownik ``game.robots`` zawiera dane wszystkich robotów na planszy.
  Metoda  ``.iteritems()`` zwraca indeks ``poz``, czyli położenie *(x,y)*
  robota, oraz słownik ``robot`` opisujący jego właściwości, czyli:

    * *player_id* – identyfikator gracza, do którego należy robot;
    * *hp* – ilość punktów HP robota;
    * *location* – tupla (x, y) oznaczająca położenie robota na planszy;
    * *robot_id* – identyfikator robota w Twojej drużynie.

* ``rg.dist(poz1, poz1)`` – zwraca matematyczną odległość między dwoma położeniami.

Robot podstawowy
*****************

Łącząc omówione wyżej trzy podstawowe reguły, otrzymujemy robota podstawowego:

.. raw:: html

    <div class="code_no">Plik <em>robot04a.py</em>. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod04a.py
    :linenos:

Wybrane działanie robota zwracamy za pomocą instrukcji ``return``.
Zwróć uwagę, jak ważna jest w tej wersji kodu **kolejność umieszczenia reguł**,
pierwszy spełniony warunek powoduje wyjście z funkcji, więc pozostałe
możliwości nie są już sprawdzane!

.. raw:: html

    <hr />

Powyższy kod można przekształcić wykorzystując zmienną pomocniczą ``ruch``,
inicjowaną działaniem domyślnym, które może zostać zmienione przez kolejne reguły.
Dopiero na końcu zwracamy ustaloną akcję:

.. raw:: html

    <div class="code_no">Plik <em>robot04b.py</em>. Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod04b.py
    :linenos:
    :emphasize-lines: 10, 13, 18, 20
    :lineno-start: 1
    :lines: 1-

Ćwiczenie 1
=============

Przetestuj działanie robota podstawowego wystawiając go do gry z samym sobą
w symulatorze. Zaobserwuj zachowanie się robotów tworząc różne układy początkowe:

.. code-block:: bash

    (env)~/robot$ python ./symuluj robot04a.py robot04b.py

Typy pól
***********

Zobaczmy, w jaki sposób dowiedzieć się, w jakim miejscu się znajdujemy,
gdzie wokół mamy wrogów lub pola, na które można wejść. Dysponując takimi
informacjami, będziemy mogli podejmować bardziej przemyślane działania.
Możliwe są dwa podejścia: wykorzystanie funkcji lub wyrażeń zbiorów (ang. *set comprehensions*)
(zob. :term:`wyrażenie listowe`) i operacji na zbiorach (zob. :term:`zbiór`).

Czy to wejście?
================

.. raw:: html

    <div class="code_no"><strong>Wersja <em>A</em></strong> (oparta na funkcjach). Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: python

    # funkcja zwróci prawdę, jeżeli "poz" wskazuje punkt wejścia
    def czy_wejscie(poz):
        if 'spawn' in rg.loc_types(poz):
            return True
        return False

.. raw:: html

    <div class="code_no"><strong>Wersja <em>B</em></strong> (oparta na zbiorach). Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: python

    # wszystkie pola na planszy jako współrzędne (x, y)
    wszystkie = {(x, y) for x in xrange(19) for y in xrange(19)}

    # punkty wejścia (spawn)
    wejscia = {poz for poz in wszystkie if 'spawn' in rg.loc_types(poz)}

    # warunek sprawdzający, czy "poz" jest w punkcie wejścia
    if poz in wejscia:
        pass

**Metody i właściwości biblioteki** *rg*:

* ``gr.loc_types(poz)`` – zwraca typ pola wskazywanego przez ``poz``:

    * ``invalid`` – poza granicami planszy(np. (-1, -5) lub (23, 66));
    * ``normal`` – w ramach planszy;
    * ``spawn`` – punkt wejścia robotów;
    * ``obstacle`` – pola zablokowane ograniczające arenę.

Czy obok jest wróg?
====================

.. raw:: html

    <div class="code_no"><strong>Wersja <em>A</em></strong> (oparta na funkcjach). Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: python

    # funkcja zwróci prawdę, jeżeli "poz" wskazuje wroga
    def czy_wrog(poz):
        if game.robots.get(poz) != None:
            if game.robots[poz].player_id != self.player_id:
                return True
        return False

    # lista wrogów obok
    wrogowie_obok = []
    for poz in rg.locs_around(self.location):
        if czy_wrog(poz):
            wrogowie_obok.append(poz)

    # warunek sprawdzający, czy obok są wrogowie
    if len(wrogowie_obok):
        pass

W powyższym kodzie metoda ``.get(poz)`` pozwala pobrać dane robota, którego
kluczem w słowniku jest ``poz``.

Wersja oparta na zbiorach wykorzystuje różnicę i cześć wspólną zbiorów.

.. raw:: html

    <div class="code_no"><strong>Wersja <em>B</em></strong> (oparta na zbiorach). Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: python

    # pola zablokowane
    zablokowane = {poz for poz in wszystkie if 'obstacle' in rg.loc_types(poz)}

    # pola zajęte przez nasze roboty
    przyjaciele = {poz for poz in game.robots if game.robots[poz].player_id == self.player_id}

    # pola zajęte przez wrogów
    wrogowie = set(game.robots) - przyjaciele

    # pola sąsiednie
    sasiednie = set(rg.locs_around(self.location)) - zablokowane

    # pola obok zajęte przez wrogów
    wrogowie_obok = sasiednie & wrogowie

    # warunek sprawdzający, czy obok są wrogowie
    if wrogowie_obok:
        pass

**Metody i właściwości biblioteki** *rg*:

* ``rg.locs_around(poz, filter_out=None)`` – zwraca listę położeń sąsiadujących
  z ``poz``. Jako ``filter_out`` można podać typy położeń do wyeliminowania, np.:
  ``rg.locs_around(self.location, filter_out=('invalid', 'obstacle'))``.

.. raw:: html

    <hr />

.. tip::

    Definicje funkcji i list czy też zbiorów należy wstawić na początku
    metody ``Robot.act()`` – przed pierwszym użyciem.


Wykorzystując powyższe "klocki" możemy napisać roboty realizujące następujące reguły:

#. Opuść jak najszybciej wejście;
#. Atakuj wrogów obok;
#. W środku broń się;
#. W ostateczności idź do środka.

Implementacje
==============

Przykładowe implementacje mogą wyglądać następująco:

.. raw:: html

    <div class="code_no"><strong>Wersja <em>A</em></strong> (oparta na funkcjach). Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod05a.py
    :linenos:

.. raw:: html

    <div class="code_no"><strong>Wersja <em>B</em></strong> (oparta na zbiorach). Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod05b.py
    :linenos:

Metoda ``.pop()`` zastosowana do listy zwraca jej ostatni element, natomiast
w przypadku zbioru zwraca element losowy.

Ćwiczenie 2
===============

Zapisz obie wersje w dwóch różnych plikach w katalogu :file:`robot` i przetestuj
je w symulatorze, a następnie wystaw je przeciw sobie do walki. Poeksperymentuj
z kolejnością reguł, która określa ich priorytety!

.. tip::

    Do kontrolowania logiki działania robota zamiast rozłącznych instrukcji
    warunkowych: ``if war1: ... if war2: ...`` itd. można użyć instrukcji
    złożonej: ``if war1: ... elif war2: ... [elif war3: ...] else: ...``.

Atakuj, jeśli nie umrzesz
**************************

Warto atakować, ale nie wtedy, gdy grozi nam śmierć. Można przyjąć zasadę,
że atakujemy tylko wtedy, kiedy suma potencjalnych uszkodzeń będzie mniejsza
niż zdrowie naszego robota. Zmień więc dotychczasowe reguły ataku wroga korzystając
z poniższych "klocków":

.. raw:: html

    <div class="code_no"><strong>Wersja <em>A</em> i <em>B</em>.</strong> Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: python

    # WERSJA A
    # jeżeli suma potencjalnych uszkodzeń jest mniejsza od naszego zdrowia
    # funkcja zwróci prawdę
    def czy_atak():
        if 9*len(wrogowie_obok) < self.hp:
            return True
        return False

    # WERSJA B
    # jeżeli obok są przeciwnicy, atakuj
    if wrogowie_obok:
        if 9*len(wrogowie_obok) >= self.hp:
            pass
        else:
            ruch = ['attack', wrogowie_obok.pop()]

**Metody i właściwości biblioteki** *rg*:

* ``self.hp`` – ilość punktów HP robota.

Ćwiczenie 3
===============

Dodaj powyższą regułę do wersji A i B robotów.

Ruszaj się bezpiecznie
***********************

Zamiast iść na oślep lepiej wchodzić czy uciekać na bezpieczne pola.
Za "bezpieczne" przyjmiemy na razie pole puste, niezablokowane i nie będące
punktem wejścia.

.. raw:: html

    <div class="code_no"><strong>Wersja <em>A</em> i <em>B</em>.</strong> Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: python

    # WERSJA A
    # funkcja zwróci prawdę jeżeli pole poz będzie puste
    def czy_puste(poz):
        if ('normal' in rg.loc_types(poz)) and not ('obstacle' in rg.loc_types(poz)):
            if game.robots.get(poz) == None:
                return True
        return False

    puste = [] # lista pustych pól obok
    bezpieczne = [] # lista bezpiecznych pól obok

    for poz in rg.locs_around(self.location):
        if czy_puste(poz):
            puste.append(poz)
        if czy_puste(poz) and not czy_wejscie(poz):
            bezpieczne.append(poz)

    # WERSJA B
    # zbiór bezpiecznych pól
    bezpieczne = sasiednie - wrogowie_obok - wejscia - przyjaciele


Atakuj 2 kroki obok
*******************

Jeżeli w odległości 2 kroków jest przeciwnik, zamiast iść w jego kierunku
i narażać się na szkody, lepiej go zaatakuj, aby nie mógł bezkarnie się
do nas zbliżyć.

.. raw:: html

    <div class="code_no"><strong>Wersja <em>A</em> i <em>B</em>.</strong> Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: python

    # WERSJA A
    # funkcja zwróci prawdę, jeżeli w odległości 2 kroków z przodu jest wróg
    def zprzodu(l1, l2):
        if rg.wdist(l1, l2) == 2:
            if abs(l1[0] - l2[0]) == 1:
                return False
            else:
                return True
        return False

    # funkcja zwróci współrzędne pola środkowego między dwoma innymi
    # oddalonymi o 2 kroki
    def miedzypole(p1, p2):
        return (int((p1[0]+p2[0]) / 2), int((p1[1]+p2[1]) / 2))

    for poz, robot in game.get('robots').items():
        if czy_wrog(poz):
            if rg.wdist(poz, self.location) == 2:
                if zprzodu(poz, self.location):
                    return ['attack', miedzypole(poz, self.location)]
                if rg.wdist(rg.toward(loc, rg.CENTER_POINT), self.location) == 1:
                    return ['attack', rg.toward(poz, rg.CENTER_POINT)]
                else:
                    return ['attack', (self.location[0], poz[1])]

    # WERSJA B
    wrogowie_obok2 = {poz for poz in sasiednie if (set(rg.locs_around(poz)) & wrogowie)} - przyjaciele

    if wrogowie_obok2:
        ruch = ['attack', wrogowie_obok2.pop()]

.. raw:: html

    <hr />

Składamy reguły
****************

Ćwiczenie 4
==============

Jeżeli czujesz się na siłach, spróbuj dokładać do robota w wersji **A**
(oparty na funkcjach) i **B** (oparty na zbiorach) po jednej z przedstawionych
reguł, czyli: 1) Atakuj, jeśli nie umrzesz; 2) Ruszaj się bezpiecznie;
3) Atakuj na 2 kroki. Przetestuj w symulatorze każdą zmianę.

Omówione reguły można poskładać w różny sposób. W wersji **A** (z funkcjami)
kod mógłby być taki:

.. raw:: html

    <div class="code_no"><strong>Wersja <em>A</em></strong> (oparta na funkcjach). Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod09a.py
    :linenos:

W wersji **B** opartej na zbiorach:

.. raw:: html

    <div class="code_no"><strong>Wersja <em>B</em></strong> (oparta na zbiorach). Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: rgkod09b.py
    :linenos:

Ćwiczenie 5
============

To nie są takie same roboty! Przetestuj je w symulatorze i wystaw kilka
razy do walki. Który jest lepszy i dlaczego?

Możliwe ulepszenia
**********************

Poniżej pokazujemy "klocki", których możesz użyć, aby zoptymalizować roboty.
Zamieszczamy również listę pytań do przemyślenia, aby zachęcić cię do
samodzielnego konstruowania najlepszego robota :-)

Atakuj najsłabszego
====================

.. raw:: html

    <div class="code_no"><strong>Wersja <em>A</em> i <em>B</em>.</strong> Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: python

    # wersja A

    # funkcja zwracająca atak na najsłabszego wroga obok
    def atakuj():
        r = wrogowie_obok[0]
        for poz in wrogowie_obok:
            if game.robots[poz]['hp'] > game.robots[r]['hp']:
                r = poz
        return ['attack', r]

    # wersja B

    # funkcja znajdująca najsłabszego wroga obok z podanego zbioru (bots)
    def minhp(bots):
        return min(bots, key=lambda x: game.robots[x].hp)

    if wrogowie_obok:
        ...
        else:
            ruch = ['attack', minhp(wrogowie_obok)]

Najkrócej do celu
==================

Funkcji ``mindist()`` można użyć do znalezienia najbliższego wroga,
aby iść w jego kierunku, kiedy opuścimy punkt wejścia:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: python

    # funkcja zwraca ze zbioru pól (bots) pole najbliższe podanego celu (poz)
    def mindist(bots, poz):
        return min(bots, key=lambda x: rg.dist(x, poz))

    # WERSJA B
    najblizszy_wrog = mindist(wrogowie,self.location)

Inne
=================

* Czy warto atakować, jeśli obok jest więcej niż 1 wróg?
* Czy warto atakować 1 wroga obok, ale mocniejszego od nas?
* Jeżeli nie można bezpiecznie się ruszyć, może lepiej się bronić?
* Jeśli jesteśmy otoczeni przez wrogów, może lepiej popełnić samobójstwo...
* Spróbuj zmienić akcję domyślną w wersji **B** korzystającej ze zbiorów.
* Spróbuj użyć jednej złożonej instrukcji warunkowej w wersji **B**.

Proponujemy, żebyś sam zaczął wprowadzać i testować zasugerowane ulepszenia.
Możesz też zajrzeć do drugiego :ref:`zestawu klocków <klocki02>`.

.. raw:: html

    <hr />
