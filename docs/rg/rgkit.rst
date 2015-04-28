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

.. note::

    Niniejsza dokumentacja jest nieautoryzowanym tłumaczeniem oficjalnej dokumentacji
    dostępnej na stonie `RobotGame <https://robotgame.net>`_.
