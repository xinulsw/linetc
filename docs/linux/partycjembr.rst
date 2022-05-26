.. _parytcjembr:

Partycje MBR
############

W standardzie `MBR (*Master Boot Record*) <https://pl.wikipedia.org/wiki/Master_Boot_Record>`_ możemy utworzyć
maksymalnie 4 `partycje <https://pl.wikipedia.org/wiki/Partycja>`_ **podstawowe**, lub 3 podstawowe i wiele
**logicznych** na parycji rozszerzonej. Linuksa zainstalować można na dowolnej z nich.

W Linuskie pierwszy wykryty napęd (dysk, pendrive) oznaczany jest jako **sda**, kolejne **sdb**, **sdc** itd.
Po nazwie dysku występuje numer oznaczający partycję główną (od 1 do 4) lub logiczną (od 5 do n).
Najczęściej wykorzystywanym `systemem plików <https://pl.wikipedia.org/wiki/System_plik%C3%B3w>`_
jest `ext4 <https://pl.wikipedia.org/wiki/Ext4>`_.

Tylko Linux
===========

Jeżeli dysk przeznaczamy w całości dla Linuksa praktycznym układem będzie:

* Partycja 1 (**sda1**) – ext4, może być aktywna (boot), na główny katalog oznaczany **/**, rozmiar 25 GB,
* Partycja 2 (**sda2** lub **sda5**) – ext4, na katalog **/home**, czyli dane użytkowników, rozmiar wedle potrzeb,
* Partycja 3 (**sda3** lub **sda6**) – swap, partycja wymiany (swap), rozmiar 2 GB

W takim przypadku problemu nie ma. Uruchamiamy instalację wybranej dystrybucji i podczas instalacji wybieramy opcję typu "Przewodnik – cały dysk" (np. Debian, Ubuntu):

<img alt="Partycjonowanie: Przewodnik – cały dysk" class="imgram" src="data/uploads/instalacja/debian/debian11.jpg" style="width: 551px; height: 413px;" />

Jeżeli instalator nie oferuje przewodnika, możemy użyć dostępnych w prawie wszystkich dystrybucjach dedykowanego graficznego programu **GParted** lub konsolowego **cfdisk** (np. w Bridge Linux). Poniżej przedstawiamy oba programy dokładniej.

<h4>Linux i Windows</h4>

Zazwyczaj w komputerze mamy już zainstalowany system Windows (nie ma wyboru!). W takim przypadku, gdy chcemy go zachować, musimy wygospodarować miejsce na Linuksa. Możliwe są różne scenariusze, omówimy więc typowe.

**Jedna partycja z Windows do usunięcia**

W nowo zakupionych notebookach mamy zazwyczaj 1 ukrytą partycję służącą do odzyskiwania systemu oraz jedną wielką partycję z Windows. Z punktu widzenia wydajności i bezpieczeństwa danych jest to układ zły, ale liczący zyski producentów to nie obchodzi. Jeżeli mamy płytę instalacyjną Windowsa lub możemy ją zdobyć (np. od znajomego lub ściągając ze stron Microsoftu), najlepszym rozwiązaniem jest sporządzenie kopii danych i usunięcie wszystkich partycji. Ponowne zainstalowanie systemu Windows pozwoli się również pozbyć całej masy zamulających i niepotrzebnych programów dołączanych przez producentów. Nowego układu partycji nie należy tworzyć za pomocą instalatora Windows, ponieważ zazwyczaj założy on dodatkową i zbędną partycję o rozmiarze 100 MB. Wykorzystujemy inne narzędzia, np. wspomniane wcześniej programy **GParted** lub&nbsp;**cfdisk**. Przykładowy nowy układ:

Partycja 1 (sda1) – podstawowa, ntfs, aktywna (boot), rozmiar 50 GB, dla Windowsa
  Partycja 2 (sda2)&nbsp;– podstawowa, ext4, rozmiar 10 GB, systemowa dla Linuksa
  Partycja 3 (sda5) – logiczna, swap, romiar 2 GB
  Partycja 4 (sda6) – logiczna, ext4, na katalog /home, czyli dane użytkowników, rozmiar wedle potrzeb, dla Linuksa
  Partycja 5 (sda7) – logiczna, ntfs lub fat32, na dane użytkowników Windowsa, również do wymiany danych między systemami, rozmiar wedle potrzeb

**Partycja z Windows do zachowania**

Jeżeli nie możemy lub nie chcemy usuwać partycji Windowsa, np. aby uniknąć reinstalacji systemu, trzeba ją zmniejszyć, a dopiero później utworzyć partycje dodatkowe. Zobacz: <a href="https://www.dobreprogramy.pl/Jak-zmniejszyc-partycjesystemowa-Windows-i-zrobic-miejsce-na-Linuksa,News,79753.html">Jak zmniejszyć partycję systemową Windows i zrobić miejsce na Linuksa?</a>

Przed zmniejszeniem należy tę partycję zdefragmentować najlepiej w taki sposób, aby pliki umieszczone zostały na jej początku. Można to zrobić np. za pomocą darmowego programu <a href="http://www.dobreprogramy.pl/Defraggler,Program,Windows,13314.html" target="_blank">Defraggler</a> z wybraną opcję defragmentowania wolnej przestrzeni.

<h4>GParted</h4>

Wszystkie opisane wyżej czynności możemy wykonać szybko i bezpiecznie za pomocą dedykowanej dystrybucji **GParted Live**. Program GParted jest również bardzo często dołączany do linuksowych dystrybucji, które po uruchomieniu w trybie Live umożliwiają jego użycie, a następnie instalację systemu. Obraz iso omawianej dystrybucji pobieramy ze strony <a href="http://gparted.org/download.php" target="_blank">GParted</a>, wypalamy na płycie lub przygotowujemy <a href="usb-boot">klucz USB</a>. Po uruchomieniu wybieramy pierwszą opcję, czyli uruchomienie w trybie Live. Na kolejnych ekranach klikamy Enter, aż zobaczymy okno podobne do poniższego:

<img alt="GParted Live" src="http://srv40578.seohost.com.pl/data/uploads/partycje/gpartedl.png" style="width: 551px; height: 413px;" />

O ile powyższy zrzut prezentuje zawartość dysku wirtualnego, o tyle poniższy pokazuje przykład z życia:

<img alt="Przykładowy układ partycji na dysku" class="imgram" src="data/uploads/partycje/gparted_01.png" style="width: 550px; height: 372px;" />

Jak widać, przykład dotyczy pierwszego dysku twardego w systemie (**/dev/sda**), na którym mamy trzy partycje podstawowe: **sda1** - Windows, system plików NTFS, **sda2** i **sda3** - Linux, system plików ext4; dalej znajduje się partycja rozszerzona **sda4**, w której ramach mamy partycje logiczne: **sda5** i **sda6** - Linux, system plików reiserfs i ext4, **sda7** - przestrzeń wymiany dla Linuksa, **sda8** - partycja dla Windowsa (NTFS) i do wymiany danych między systemami. Zapamiętać tu można, że Windows wykorzystuje system plików **NTFS**, czasami FAT32, natomiast Linux najczęściej&nbsp;**ext4** lub rzadziej&nbsp;**reiserfs** (oczywiście to nie jedyne dostępne w Linuksie typy systemów plików).

Przejdźmy do typowych zadań związanych z partycjonowaniem. Po zaznaczeniu wybranej partycji, np. systemowej Windows, i wybraniu polecenia <em>Zmień rozmiar/przenieś</em> (dostępnegop też, jak większość poleceń, w menu podręcznym prawego klawisza myszki), zobaczymy okno, w którym albo podajemy ilość wolnego miejsca, które ma zostać zwolnione za partycją, albo ustalamy to przeciągając graficzny uchwyt myszką:

<img alt="Zmiana rozmiaru partycji" class="imgram" src="data/uploads/partycje/pmagic_09.jpg" style="width: 550px; height: 373px;" />

To, ile miejsca uda się zwolnić, zależy oczywiście od tego, ile danych zawiera zmniejszana partycja. Przesadzić nie można, każdy system wymaga min. kilku wolnych GB do poprawnego działania. Po wygospodarowaniu wolnego miejsca w wyniku zmniejszenia lub usunięcia partycji zaznaczamy obszar oznaczony jako "nieprzydziolone", wybieramy polecenie <em>Nowa</em> i tworzymy partycje podstawową w zalezności od scenariusza dla Windowsa lub Linuksa:

<img alt="Tworzenie nowej partycji podstawowej" class="imgram" src="data/uploads/partycje/pmagic_10.jpg" style="width: 550px; height: 373px;" />

Po utworzeniu partycji podstawowych (maks. 3), trzeba stworzyć partycję rozszerzoną, a w niej pozostałe partycje logiczne, np. wymiany (swap):

<img alt="Tworzenie partycji rozszerzonej" class="imgram" src="data/uploads/partycje/pmagic_11.jpg" style="height: 373px; width: 550px;" />

<img alt="Tworzenie partycji wymiany (swap)" class="imgram" src="data/uploads/partycje/pmagic_12.jpg" style="width: 550px; height: 373px;" />

W razie potrzeby można oznaczyć wybraną partycję podstawową jako aktywną (boot), klikając ją prawym klawiszem i wybierając polecenie <em>Zarządzaj flagami</em>. Wykonane operacje trzeba na koniec zatwierdzić poleceniem <em>Zastosuj</em>. Dopóki tego nie zrobimy żadne zmiany nie są zapisywane na dysku, a my możemy dowolnie modyfikować podjęte działania (np. usunięcie niepotrzebnej czy za małej partycji i założenie innej itd.) Przykładowy układ po zatwierdzeniu zmian:

<img alt="Przykładowy układ partycji po zmianach" class="imgram" src="data/uploads/partycje/pmagic_13.jpg" style="width: 550px; height: 373px;" />

W galerii <a href="part-gparted" target="_blank">Partycjonowanie z GParted</a> zamieszczono jeszcze kilka dodatkowych zrzutów.

<h4>Cfdisk</h4>

<img alt="Partycjonowanie: cfdisk" class="imgram" src="data/uploads/partycje/cfdisk11.jpg" style="width: 550px; height: 360px;" />

Obsługa programu **cfdisk** jest intuicyjna. Strzałkami **góra/dół** zaznaczamy (podświetlenie) partycję lub wolne miejsce ("Free Space"), a strzałkami **lewo/prawo** wybieramy działanie: [ **Bootable** ] – ustawienie flagi uruchomieniowej na partycji, [ **Delete** ] – usunięcie partycji, [ **New** ] – utworzenie nowej partycji, [ **Type** ] – określenie typu partycji (82 – Linux swap, 83 – Linux), [ **Write** ] – zapisanie układu partycji, [ **Quit**&nbsp;] – wyjście z programu. Wybraną akcję zatwierdzamy naciśnięciem **Enter**. W galerii <a href="part-cfdisk">Partycjonowanie z cfdisk</a> pokazaliśmy typowe operacje.

<h4>Ile systemów na jednym dysku?</h4>

Odpowiedź krótka, tyle, ile mamy chęci i wolnego miejsca. Kolejny przykład z życia (11 systemów):

<img alt="Wiele systemów na jednym dysku" class="imgram" src="data/uploads/partycje/gparted_02.png" style="width: 550px; height: 357px;" />

Jeżeli chcemy mieć na dysku kilka dystrybucji Linuksa (opcjonalnie razem z Windowsem) podczas instalacji jedenej z nich (np. pierwszej, nazwijmy ją "Głównej") zainstalujmy GRUBa (bootmenedżer) w głównym sektorze dysku (MBR), będzie on obsługiwał wszystkie inne systemy. Instalację bootmenedżerów kolejnych dystrybucji albo pomijamy, albo wskazujemy jako miejsce partycję przeznaczoną dla katalogu głównego <span class="katalog">&nbsp;/ </span>&nbsp;(czyli **sdaN**). Pamiętać musimy, że po doinstalowaniu kolejnej dystrybucji lub po aktualizacji jądra w którymś z systemów, należy zaktualizować konfiguraję GRUBa zainstalowanego w MBR. W tym celu w dystrybucji "głównej" trzeba uruchomić z uprawnieniami administracyjnymi polecenie <code>(sudo) update-grub2</code>:

<img alt="Aktualizacja konfiguracji bootmenedżera GRUB" class="imgram" src="data/uploads/partycje/update_grub2.jpg" style="width: 550px; height: 390px;" />

[...]