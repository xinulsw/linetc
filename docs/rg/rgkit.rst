Testowanie robotów
###################

Pakiet **rgkit**
******************

Do testowania robotów najlepiej użyć pakietu *rgkit*. W tym celu przygotowujemy
środowisko deweloperskie, dostarczające bibliotekę ``rg``:

.. code-block:: bash

    ~$ mkdir robot; cd robot
    ~robot/$ virtualenv env
    ~robot/$ source env/bin/activate
    (env):~robot$ pip install rgkit

Po wykonaniu powyższych poleceń i zapisaniu implementacji klasy ``Robot``
np. w pliku :file:`~/robot/robot1.py` możemy uruchamiać grę przeciwko
robotom domyślnym za pomocą polecenia:

.. code-block:: bash

    (env)~/robot$ rgrun robot1.py defaultsrobot.py

Jeżeli utworzymy mamy inne implementacje robotów, np.
w pliku :file:`~/robot/robot2.py` użyjemy:

.. code-block:: bash

    (env)~/robot$ rgrun robot1.py robot2.py

Przydatne opcje polecenia ``rgrun``:

* ``-H`` – symulacja bez UI
* ``-c COUNT`` – liczba gier uruchamianych jednocześnie, domyślnie: 1
* ``-r`` – roboty wprowadzane losowo zamiast symetrycznie.

.. attention::

    Pokazana powyżej instalacja zakłada użycie środowiska wirtualnego tworzonego
    przez pakiet ``virtualenv``, dlatego przed uruchomieniem symulacji za pomocą
    polecenia ``rgrun``, a także przed użyciem omówionego niżej
    pakietu ``robotgame-bots`` trzeba pamiętać o wydaniu polecenia
    ``source env/bin/activate`` w katalogu :file:`robot`.

Roboty open-source
*******************

Swoje roboty warto wystawić do gry przeciwko przykładowym robotom
dostarczanym przez projekt `robotgame-bots <https://github.com/mpeterv/robotgame-bots>`_:
Instalacja sprowadza się do wykonania polecenia:

.. code-block:: bash

    ~/robot$ git clone https://github.com/mpeterv/robotgame-bots bots

Wynikiem polecenia będzie utworzenia podkatalogu :file:`~/robot/bots` zawierającego
kod przykładowych robotów. Aby zmierzyć się z nimi, wydajemy polecenie:

.. code-block:: bash

    (env)~/robot$ rgrun mojrobot.py bots/nazwa_pliku_robota.py

Listę dostępnych robotów najłatwiej użyskać wydając polecenie:

.. code-block:: bash

    (env)~/robot$ ls bots

Od czasu do czasu można zaktualizować dostępne roboty poleceniem:

.. code-block:: bash

    ~/robot/bots$ git pull --rebase origin master

Symulator rg
*************

Bardzo przydatny jest symulator zachowania robotów. Instalacja:

.. code-block:: bash

    ~/robot$ git clone https://github.com/mpeterv/rgsimulator.git

Następnie uruchamiamy symulator podając jako parametr nazwę przynajmniej
jednego robota (można dwóch):

    .. code-block:: bash

    (env)~/robot$ rgsimulator/rgsimulator.py robot01.py [robot02.py]

Symulatorem sterujemy za pomocą klawiszy:

* Klawisze kursora lub WASD do zaznaczania pól.
* Klawisz F: utworzenie robota-przyjaciela w zaznaczonym polu.
* Klawisz E: utworzenie robota-wroga w zaznaczonym polu.
* Klawisze R, Delete or Backspace: usunięcie robota z zaznaczonego pola.
* Klawisz H: zmiana punktów HP robota.
* Klawisz T: zmiana rundy.
* Klawisz C: wyczysczenie planszy gry.
* Klawisz Spacja: pokazuje planowane ruchy robotów.
* Klawisz Enter: uruchomienie rundy.
* Klawisz L: załadowanie meczu z robotgame.net. Należy podać tylko numer meczu.
* Klawisz K: załadowanie podanej rundy z załadowanego meczu. Also updates the simulator turn counter.
* Klawisz P: zamienia kod robotów gracza 1 z 2.
* Klawisz O: ponowne załadowanie kodu obydwu robotów.
* Klawisz N: zmienia działanie robota, wyznacza "następne działanie".
* Klawisz G: tworzy i usuwa roboty w punktach wejścia (ang. *spawn locations*), "generowanie robotów".


.. note::

    Niniejsza dokumentacja jest nieautoryzowanym tłumaczeniem oficjalnej dokumentacji
    dostępnej na stonie `RobotGame <https://robotgame.net>`_, a także `RobotGame – rgkit <https://github.com/RobotGame/rgkit>`.
    Opis działania symulatora robotów przetłumaczono na podstawie strony
    projektu `rgsimulator <https://github.com/mpeterv/rgsimulator>`.
