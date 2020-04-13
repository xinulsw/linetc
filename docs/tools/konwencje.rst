Konwencje
#########

Linux
=====

Dystrybucji systemu Linux jest bardzo dużo, nasze instrukcje dotyczą systemu Ubuntu
i pokrewnych, tzn. opartych na Debianie i używających menedżera pakietów ``apt``,
np. Linux Mint.

Katalog główny w systemie Linux oznaczany jest znakiem ``/`` (ukośnik, ang. *slash* ).
Znak ten jest również separatorem katalogów w ścieżkach, np. :file:`/home/user/.config`.

Większość działań polega na wpisywani poleceń w terminalu. Terminali w Linuksie jest wiele,
domyślny dla danego systemu znajdziesz pod nazwą "Terminal".

Prefiks ``~S`` nie jest częścią polecenia, ale znakiem zachęty.
Symbol ``~`` oznacza :term:`katalog domowy` użytkownika, znak ``$`` wskazuje, że
terminal uruchomiony jest z uprawnieniami zwykłego użytkownika. Znak zachęty może opcjonalnie
zawierać katalog, w którym należy wydać polecenie, np. ``~/projekt$``.

Jeżeli jakieś działanie wymaga uprawnień administracyjnych, polecenie będzie poprzedzone
wywołaniem ``sudo``, np. ``sudo apt install geany``.

Windows
=======

W systemie Windows podstawowym terminalem jest wiersz poleceń uruchamiany komendą ``cmd``.
Lepszym wyborem jest PowerShell, a w przypadku repozytoriów Git Bash – terminal instalowany razem z kientem
Git.

W systemie Windows partycja systemowa (w pewnym stopniu odpowiednik katalogu głównego) oznaczana jest jako
``C:\``. Separatorem katalogów w ścieżkach jest znak ``\`` (odwrócony ukośnik, ang. *backslash* ).

Jeżeli jakieś polecenie wymaga uprawnień administracyjnych, należy wydać je w terminalu uruchomionym
po wybraniu opcji "Uruchom jako administrator".