*Gra robotów* – poziom wyżej
############################

Zacznijmy od znanego
*********************************
W poprzednim poradniku zaczęliśmy od bota wyposażonego w następujące funkcje:

* Broń się w środku planszy
* Atakuj wrogów obok
* Idź do środka

Zmieniliśmy lu dodaliśmy następujące funkcję:

* Opuść wejście
* Uciekaj, jeśli masz zginąć
* Atakuj wrogów dwa kroki obok
* Wchodź na bezpieczne, niezajęte pola
* Idż na wroga, jeśli w pobliżu go nie ma

Do powyższych dodamy kolejne funkcje w postaci fragmentów kodu wymagających
zmian. Trzeba zintergrować je z kodem dotychczasowego bota, aby go ulepszyć.

Kolejne funkcje
****************

Śledź miejsca, na których byliśmy wcześniej
Keep track of spots that are taken by our previous moves

To raczej złożona funkcja, ale jest potrzebna, aby zmniejszyć ilość kolizji.
Dotychczasowe boty drużyny próbują wejść na to samo miejsce i atakują się nawzajem.
Co prawda nie tracimy wtedy pukntów życia, ale (prawie) zawsze mamy lepszy wybór.
Jeżeli będziemy śledzić wszystkie nasze ruchy w ramach danej rundy, możemy
uniknąć niepotrzebnych konfliktów. Niestety, to wymaga wielu fragementów kodu.
Na początku dodamy zmienną, która posłuży do sprawdzenia, czy dany robot
jest pierwszym wywoływanym w rundzie. Jeżeli tak, musimy wyczyścić listę
poprzednich ruchów i zaktualizować licznik rund. Odpowiedni kod trzeba
umieścić na początku ``Robot.act``:

.. attention::

    Trzeba zainicjować zmienną globalną ``turn_number``.

.. code-block:: python

    global turn_number, taken_moves
    if game.turn != turn_number:
        turn_number = game.turn
        taken_moves = set()

Kolejne fragmenty odpowiadać będzie za zapamiętywanie wykonywanych ruchów.
Kod najwygodniej umieścić w jednej funkcji, która zanim zwróci
podjęty ruch, zapisze go na liście. Warto zauważyć, że zapisywane będą
współrzędne pól, na które wchodzimy lub na których pozostajemy (obrona, atak,
samobójstwo). Funkcja musi znaleźć się w klasie Robot.act,
aby współdzieliła jej przestrzeń nazw.

.. code-block:: python

    # Jeżeli się ruszamy, zapisujemy docelowe pole

    def moving(loc):
        taken_moves.add(loc)
        return ['move', loc]

    # Jeżeli pozostajemy w miejscu, zapisujemy aktualne położenie
    # przy użyciu self.location

    def staying(act, loc=None):
        taken_moves.add(self.location)
        return [act, loc]

Kolejnym krokiem jest usunięcie listy wykonanych ruchów (``taken_moves``)
ze zbioru bezpiecznych pól, które są podstawą dalszych wyborów:

.. code-block:: python

    safe = adjacent - adjacent_enemy - adjacent_enemy2 - spawn - team - taken_moves

Roboty atakujące dwa kroki obok często otaczają przeciwnika (to dobrze),
ale uniemożliwiają innym członkom drużyny wyjście z takiego okrążenia.
Dlatego możemy blokować ataki na pola adjacent_enemy2, jeśli wymagają
ruchu na zajęte pola.

[Robots that attack two moves away often form a perimeter around the enemy
(a good thing) but it prevents your own bots from moving across the line.
For that reason we can choose to not let a robot do an an adjacent_enemy2
attack if they are sitting in a taken spot.]

.. code-block:: python

    elif adjacent_enemy2 and self.location not in taken_moves:

Na koniec podmieniamy kod zwracający ruchy:

.. code-block:: python

    move = ['move', mindist(safe, closest_enemy)]
    move = ['attack', adjacent_enemy.pop()]

– tak aby wykorzystywał nowe funkcjce:

.. code-block:: python

    move = moving(mindist(safe, closest_enemy))
    move = staying('attack', adjacent_enemy.pop())

One caveat is that bots are not allowed to swap places. With the current code it is possible to have two bots try to swap places but fail.

Attack the weakest adjacent bot instead of a random one
*******************************************************

Any successful attack reduces the enemy's total HP in the same way, but the game is scored by total bots alive, not by bot HP. For that reason it's more important to kill a weak bot that it is to attack/weaken a strong one. We can put this function inside Robot.act and use it to select a robot from a list instead of using .pop()

.. code-block:: python

    # Function to find bot with the least health
    def minhp(bots):
        return min(bots, key=lambda x: robots[x].hp)

    elif adjacent_enemy:
        ...
        else:
            move = staying('attack', minhp(adjacent_enemy))

Suicide if we have no better options
**************************************

Right now we try to run away if we're going to die, but sometimes we won't run away successfully and we'll run into an enemy attack. If there's nowhere safe to move and we're going to die by staying still, we could suicide instead and possibly hit the enemy harder than just attacking.

.. code-block:: python

    elif adjacent_enemy:
        if 9*len(adjacent_enemy) >= self.hp:
            if safe:
                move = moving(mindist(safe, rg.CENTER_POINT))
            else:
                move = staying('suicide')
        else:
            move = staying('attack', minhp(adjacent_enemy))

Run away from uneven matchups
*****************************

When fighting one on one no one has an advantage because the enemy can attack you for every attack you make when you are adjacent. If an enemy outnumbers you by having two robots next to a single robot of yours, your robot will get hit twice for every hit you dish out. That's bad for you so, we should avoid those situations by moving away if we are outnumbered. As an aside this concept is critical to success in Robotgame even at the highest level. Fighting asymmetrically is important to success in almost any form of combat.

.. code-block:: python

    elif adjacent_enemy:
        if 9*len(adjacent_enemy) >= self.hp:
            ...
        elif len(adjacent_enemy) > 1:
            if safe:
                move = moving(mindist(safe, rg.CENTER_POINT))
        else:
            move = staying('attack', minhp(adjacent_enemy))

Chase weak robots
******************

If we know that weak robots are going to run, then instead of attacking them while they scurry away, we can chase them. This puts pressure on them to move again next turn and eventually you may be able to force them into a bad position. We'll pick robots that have health less than or equal to 5 as weak, because we'll kill those robots with collision damage even if they attack instead of fleeing.

.. code-block:: python

    elif adjacent_enemy:
        ...
        else:
            target - minhp(adjacent_enemy)
            if game.robots[target].hp <= 5:
                move = moving(target)
            else:
                move = staying('attack', minhp(adjacent_enemy))

One thing to note is that there is a natural counter to the strategy of chasing weak bots. If the weak bot guards, then the chasing bot takes collision damage, but the weak bot doesn't. The counter to that strategy is for the chasing bot to attack instead of chasing, which completes the rock-paper-scissors loop.

Summary
***********

To summarize, these are the features that we added:

* Keep track of spots that are taken by our previous moves
* Suicide if we have no better options
* Attack the weakest adjacent bot instead of a random one
* Run away from uneven matchups
* Chase weak robots

These changes together lead to a bot similar to the open-source simplebot. Check it out for more ideas on how to improve this bot. What we've been building so far is a bot that follows a set of rules, but in the next guide we'll take a look at bots with other methods of deciding what move to take in addition to a few more rule-based bot tweaks.

If you are ready for advanced concepts check out the advanced strategy guide (coming soon...)

.. raw:: html

    <hr />

.. note::

    Niniejsza dokumentacja jest swobodnym i nieautoryzowanym tłumaczeniem dokumentacji
    dostępnej na stonie `Robotgame Intermediate Strategy
    <https://github.com/ramk13/robotgame/blob/master/strategy_guide/robotgame_intermediate_strategy.md>`_.
