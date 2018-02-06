.. _interpreter-pythona:

Interpreter Pythona
###################

W systemach **Linux** Python jest szeroko stosowany i dostępny jest w ramach
standardowej instalacji większości dystrybucji i to zarówno w wersji 2.x,
jak i 3.x. Dla formalności polecenia instalacyjne to:

.. code-block:: bash

    ~$ sudo apt-get install python2 python3
    ~# pacman -S python python2

.. note::

    Warto zauważyć, że w dystrybucjach opartych na Debianie polecenie ``python``
    jest dowiązaniem do wersji 2.x, a paczki nazywają się odpowiednio ``python2-...``
    lub ``python3-...``. W Arch Linuksie i pochodnych nazwa ``python`` domyślnie
    wskazuje wersję 3.x (!), podobnie nazwy pakietów dodatkowych. Wersja i paczki
    z liniii 2.x mają w nazwie ``python2``.

Polecić natomiast można doinstalowanie dodatkowych narzędzi, w tym rozszerzonej konsoli:

.. code-block:: bash

    ~$ sudo apt-get install ipython2 ipython3
    ~# pacman -S python-pip ipython python2-pip ipython2

W **MS Windows** postępuj zgodnie z `instrukcją na Python101 <http://python101.readthedocs.io/pl/latest/env/windows.html>`_.

Materiały
=========

1. `Język Python`_

.. _Język Python: https://www.python.org/
