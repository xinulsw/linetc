*Gra robotów* – strategia podstawowa
####################################

Przykład robota
*****************

.. code-block:: python

    import rg

    class Robot:
        def act(self, game):
            # if we're in the center, stay put
            if self.location == rg.CENTER_POINT:
                return ['guard']

            # if there are enemies around, attack them
            for loc, bot in game.robots.iteritems():
                if bot.player_id != self.player_id:
                    if rg.dist(loc, self.location) <= 1:
                        return ['attack', loc]

            # move toward the center
            return ['move', rg.toward(self.location, rg.CENTER_POINT)]

W powyższym kodzie warto zauważyć trzy cechy:

* stój w miejscu, jeżeli jesteś w środku planszy;
* atakuj przeciwnika, jeeżeli jest w sąsiedztwie;
* przemieszczaj się w kierunku środka.

To pozwala nam rozpocząć grę, ale wiele możemy też dodać. Większość usprawnień (ang. *feature*),
które zostaną omówione, to rozszerzenia wersji podstawowej. Można więc wybierać
tylko te, które nam odpowiadają, i konstruować takie roboty, jakie chcemy.

Startegie indywidualne
***********************

Rozbudujmy przykład podstawowy. Oto lista przykładowych usprawnień:

* **Ulepszenie 1: opuść punkt wejścia.**

Pozostawanie w punkcie wejścia nie jest dobre. Sprawdźmy, czy jesteśmy
w punkcie wejścia i czy powinniśmy z niego wyjść. Nawet wtedy, gdy jest
ktoś do zaatakowania, ponieważ nie chcemy zostać zamknięci w pułapce wejścia.

* **Ulepszenie 2: uciekamy, jeśli grozi nam śmierć.**

Przykładowy robot atakuje aż do śmierci. Ponieważ jednak wygrana zależy od
liczby pozostałych robotów, a nie ich zdrowia, bardziej opłaca się zachować
robota niż poświęcić go na zadanie dodakowych obrażeń przeciwnikowi. Jeżeli
więc jesteśmy zagrożeni śmiercią, uciekamy, a nie giniemy na próżno.

* **Ulepszenie 3: Atakujemy przeciwnika o dwa kroki od nas.**

Przyjrzyj się jakiemuś przestrzegającemu reguł robotowi, zauważysz, że kiedy wchodzi na pole
atakowane przez przeciwnika, odnosi obrażenia. Dlatego, jeśli prawdopodobne jest,
że przeciwnik może znaleźć się w naszym sąsiedztwie, trzeba go atakować. To zapobiega
zbliżaniu się do nas bez ponoszenia konsekwencji.


.. note::

    Połączenie ucieczki i ataku w kierunku przeciwnika rzeczywiście jest skuteczne.
    Każdy agresywny wróg zanim nas zaatakuje, sam spotyka się z atakiem.
    Jeżeli w porę odskoczysz, zanim się zbliży, działanie takie możesz powtórzyć.
    W grach technika ta nazywana jest `kiting <http://gaming.stackexchange.com/questions/18903/what-is-kiting>`_,
    a jej działanie ilustruje poniższa animacja:

.. figure:: img/kiting.gif

    Zwróć uwagę na słabego robota ze zdrowiem 8 HP, który podchodzi do mocnego robota
    z 50 HP, a następnie ucieka. Zbliżając się atakuje pole, na które wchodzi przeciwnik,
    ucieka i ponawia działanie. trwa to do momentu, kiedy silniejszy robot popełni samobójstwo
    (co w tym wypadku jest mało przydatne). Wszystko bez uszczerbku na zdrowiu słabszego
    robota.

* **Ulepszenie 4: przesuwamy się tylko na wolne pola.**

Przykładowy robot idzie do środka planszy, ale w wielu wypadkach lepiej zrobić
coś innego. Lepiej iść tam, gdzie jest bezpiecznie, niż narażać się na
bezużyteczne niebezpieczeństwo. Co jest więc ryzykowne? Po wejściu na plansze:
ruch na pole przeciwnika lub wchodzenie w jego sąsiedztwo. Wiemy też, że
nie możemy wejść na zajęte pola. Możemy też zmniejszyć ilość kolizji,
nie wchodząc na pola zajęte przez naszą drużynę.

* Ulepszenie 5: Idź na wroga, jeżeli go nie ma w zasięgu dwóch kroków.

Skoro mamy kilka bezpiecznych możliwości, po co iść do środka? Wiemy, że
pozostawianie w punkcie wejścia jest złe, ale to nie czyni środka dobrym.
Lepszym wyborem jest ruch w kierunku, ale nie na pole, przeciwnika.
W połączeniu z atakiem daje nam to lepszą kontrolę nad planszą.
Później przekonamy się jeszcze, że są sytuacje, kiedy wejście na
potencjalnie niebezpieczne pole warte jest ryzyka, ale na razie poprzestańmy
na tym, co ustaliliśmy.


Łączenie ulepszeń
*******************

Zapiszmy wszystkie ulepszenia w pseudokodzie. Możemy użyć do tego jednej
rozbudowanej instrukcji warunkowej if/else.

.. code-block:: python

    jeżeli jesteś w punkcie wejścia:
        rusz się bezpiecznie (np. poza wejście)
    jeżeli jeddnak mamy przeciwnika o krok dalej:
        jeżeli możemy umrzeć:
            ruszamy się w bezpieczne miejsce
        w przeciwnym razie:
            atakujemy przeciwnika
    jeżeli jednak mamy przeciwnika o dwa kroki dalej:
        atakujemy w jego kierunku
    jeżeli mamy bezpieczny ruch (i nikogo wokół siebie):
        ruszamy się bezpiecznie, ale w kierunku przeciwnika
    w przeciwnym razie:
        bronimy się w miejscu, bo nie ma gdzie ruszyć się lub atakować

Implementacja
****************

Do zakodowania omówionej logiki potrzebujemy struktury danych gry z jej
ustawieniami i kilku funkcji. Pamiętajmy, że jest wiele sobosobów na zapisanie
kodu w Pythonie. Poniższy w żdanym razie nie jest optymalny, ale działa
jako przykład.

Zbiory zamiast list
********************

Dla ułatwienia użyjemy pythonowych zbiorów razem z funkcją ``set()``
i wyrażeniami zbiorów (ang. *set comprehensions*).

.. note::

    Zbiory i operacje na nich omówiono w `dokumentacji zbiorów <https://docs.python.org/2/library/sets.html>`_,
    podobnie przykłady `wyrażeń listowych i odpowiadających im pętli <https://docs.python.org/2/tutorial/datastructures.html#list-comprehensions>`_.

Podstawowe operacje na zbiorach, których użyjemy to:

* ``|`` lub suma – zwraca zbiór wszystkich elementów zbiorów;
* ``-`` lub różnica – zbiór elementów obecnych tylko w pierwszym zbiorze;
* ``&`` lub część wspólna – zwraca zbiór elementów występujących w obydwu zbiorach.

Załóżmy, że zaczniemy od wygenerowania następujących list:
``drużyna`` – członkowie drużyny, ``wrogowie`` – przeciwnicy,
``wejścia`` – punkty wejścia oraz ``przeszkody`` – położenia zablokowane.

Podstawowe struktury danych
****************************

.. code-block:: python

    all_locs = {(x, y) for x in xrange(19) for y in xrange(19)}
    spawn = {loc for loc in all_locs if 'spawn' in rg.loc_types(loc)}
    obstacle = {loc for loc in all_locs if 'obstacle' in rg.loc_types(loc)}
    team = {loc for loc in game.robots if game.robots[loc].player_id == self.player_id}
    enemy = set(game.robots)-team

Warto zauważyć, jak utworzyliśmy zbiór wrogich robotów, jest to różnica
zbioru wszystkich robotów i naszej drużyny.

Użyteczne zbiory i funkcje
****************************

Przy poruszaniu się i atakowaniu mamy tylko cztery możliwe kierunki, które
zwróci nam funkcja ``rg.locs_around``. Możemy wykluczyć położenia zablokowane
(*obstacle*), ponieważ nigdy ich nie zajmujemy i nie atakujemy. Wyrażenie
``adjacent & enemy`` zwróci nam sąsiednie położenia zajęte przez przeciwników:

.. code-block:: python

    adjacent = set(rg.locs_around(self.location)) - obstacle
    adjacent_enemy = adjacent & enemy

Aby odnaleźć wrogów oddalonych o dwa kroki, szukamy przyległych kwadratów
z przeciwnikami obok. Wyłączamy sąsiednie pola zajęte przez członków drużyny.

.. code-block:: python

    adjacent_enemy2 = {loc for loc in adjacent if (set(rg.locs_around(loc)) & enemy)} - team team

Teraz musimy sprawdzić, które z położeń są bezpieczne. Usuwamy pola zajmowane
przez przeciwników w odległości 1 i 2 kroków. Pozbyway się także punktów
wejścia, nie chcemy na nie wracać. Podobnie, aby zmniejszyć możliwość kolizji,
wyrzucamy pola zajmowane przez drużynę. W miarę komplikowania logiki będzie
można zastąpić to ograniczenie dodatkowym warunkiem, ale na razie to
najlepsze, co możemy zrobić.

.. code-block:: python

    safe = adjacent - adjacent_enemy - adjacent_enemy2 - spawn - team

Potrzebujemy funkcji, która wybierze nam ze zbioru położeń najbliższe
podanego. Możemy użyć tej funkcji do znalezienia najbliższego wroga,
jak również do wyboru pola z bezpiecznej listy. Możemy wybrać ruch najbardziej
przybliżający nas do założonego celu.

.. code-block:: python

    def mindist(bots, loc):
        return min(bots, key=lambda x: rg.dist(x, loc))

Możemy użyć metody ``pop()`` zbioru, aby pobrać jego dowolny element, np.
przeciwnika, którego zaatakujemy. Żeby dowiedzieć się, czy jesteśmy zagrożeni
śmiercią, możemy pomnożyć liczbę sąsiadujących przeciwników przez średni
poziom uszkodzeń (9 punktów HP) i sprawdzić, czy mamy więcej siły.
Ze względu na sposób napisania naszej funkcji ``minidist()``
musimy pamiętać o przekazywaniu jej niepustych zbiorów. Jeśli np. zbiór
przeciwników będzie pusty, funkcja zwróci błąd.

Składamy wszystko razem
************************

Po złożeniu wszystkich kawałków kodu razem otrzymujemy przykładową
implemetację robota wyposażonego we wszystkie założone wyżej właściwości:

.. code-block:: python

    import rg

    class Robot:
        def act(self, game):
            all_locs = {(x, y) for x in xrange(19) for y in xrange(19)}
            spawn = {loc for loc in all_locs if 'spawn' in rg.loc_types(loc)}
            obstacle = {loc for loc in all_locs if 'obstacle' in rg.loc_types(loc)}
            team = {loc for loc in game.robots if game.robots[loc].player_id == self.player_id}
            enemy = set(game.robots)-team

            adjacent = set(rg.locs_around(self.location)) - obstacle
            adjacent_enemy = adjacent & enemy
            adjacent_enemy2 = {loc for loc in adjacent if (set(rg.locs_around(loc)) & enemy)} - team
            safe = adjacent - adjacent_enemy - adjacent_enemy2 - spawn - team

            def mindist(bots, loc):
                return min(bots, key=lambda x: rg.dist(x, loc))

            if enemy:
                closest_enemy = mindist(enemy,self.location)
            else
                closest_enemy = rg.CENTER_POINT

            # akcja domyślna, którą nadpiszemy, jak znajdziemy coś lepszego
            move = ['guard']

            if self.location in spawn:
                if safe:
                    move = ['move', mindist(safe, rg.CENTER_POINT)]
            elif adjacent_enemy:
                if 9*len(adjacent_enemy) >= self.hp:
                    if safe:
                        move = ['move', mindist(safe, rg.CENTER_POINT)]
                else:
                    move = ['attack', adjacent_enemy.pop()]
            elif adjacent_enemy2:
                move = ['attack', adjacent_enemy2.pop()]
            elif safe:
                move = ['move', mindist(safe, closest_enemy)]

            return move

.. raw:: html

    <hr />

.. note::

    Niniejsza dokumentacja jest swobodnym i nieautoryzowanym tłumaczeniem dokumentacji
    dostępnej na stonie `Robotgame basic strategy
    <https://github.com/ramk13/robotgame/blob/master/strategy_guide/robotgame_basic_strategy.md>`_.
