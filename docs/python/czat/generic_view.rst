Widoki ogólne
**************************

Zajmiemy sie teraz drugim sposobem stworzenia formularza rejestracji, logowania
i wylogowania. Formularze te bowiem działają, ale nie do końca tak jak powinny.
Spróbuj zarejestrować dodanego już użytkownika, albo przesłać niepełny
formularz. Zauważysz, że nie dostajemy żadnej informacji o błędach.
Można oczywiście dopisać ich obsługę do odpowiednich widoków lub wygenerować
je w szablonach, ale... wcale nie trzeba tego robić. W przypadku prostych
aplikacji wystarczą wbudowane w Django widoki ogólne (ang. *generic views*)
i formularze.

Wszystko da się zrobić w pliku ``urls.py``, który zmieniamy następująco:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. highlight:: python
.. literalinclude:: urls_z5.py
    :linenos:
    :emphasize-lines: 10-19
    :lineno-start: 10
    :lines: 10-

Na początku importujemy widok przeznaczony do dodawania danych
(``CreateView``), następnie formularz tworzenia użytkownika (``UserCreationForm``)
i logowania (``AuthenticationForm``). Do generowania adresów url
potrzebna będzie również funkcja ``reverse_lazy()``.

Następnie zakomentowujemy dotychczasowe powiązania adresów i widoków.
Dodajemy natomiast nowe. Do adresu */rejestruj* przypisujemy wywołanie
metody ``as_view()`` widoku ogólnego ``CreateView``. Do obsłużenia adresów */loguj*
i */wyloguj* używamy dedykowanych widoków ``login`` i ``logout``.

Na działanie widoków wpływają przekazywane im w różny sposób ustawienia właściwości,
takie jak:

* ``template_name`` – szablon, który zostanie użyty do zwrócenia odpowiedzi;
* ``form_class`` – formularz, który zostanie przekazany do szablonu;
* ``success_url`` – adres, na który nastąpi przekierowanie w przypadku braku błędów
  (np. po udanej rejestracji);
* ``next_page`` – adres strony, na który nastąpi przekierowanie użytkownika
  po wykonaniu żądanych akcji (np. udanym wylogowaniu).

Pozostaje nam jeszcze określić stronę, na którą powinien zostać przekierowany
użytkownik po udanym zalogowaniu. W tym wypadku na końcu pliku :file:`settings.py`
definujemy wartość zmiennej ``LOGIN_REDIRECT_URL``:

.. raw:: html

    <div class="code_no">Kod nr <script>var code_no = code_no || 1; document.write(code_no++);</script></div>

.. code-block:: python

    # czat/czat/settings.py

    from django.core.urlresolvers import reverse_lazy
    LOGIN_REDIRECT_URL = reverse_lazy('index')

To wszystko. Zauważ, że funkcje ``rejestruj()``, ``loguj()`` i ``wyloguj()``,
które umieściliśmy wczesniej w pliku :file:`views.py` nie są już potrzebne!
Przetestuj teraz działanie formularza rejestracji! Spróbuj dodać
zarejestrowanego już użytkownika, wysłać pusty lub niekompletny formularz.