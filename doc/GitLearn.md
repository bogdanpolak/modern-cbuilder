# Praca z Git

Komunikacja z repozytorium Git oraz zarządzanie nim wykonuje się z linii poleceń przez program `git.exe` (Windows). Podstawowe polecenia git to:

* `git clone <repo-URL>`
    * Klonuje repozytorium zdalne, czyli pobiera wszystkie rewizje oraz informacje o wskaźnikach zdalnych. Zakłada gałąź główną `master` oraz alias `origin` zawierający adres repozytorium zdalnego.
* `git status`
    * Zwraca informację o niezarejestrowanych zmianach w katalogu roboczym oraz o zmianach zarejestrowanych w poczekalni, które czekają na zatwierdzenie
* `git add .`
    * Dodaje do poczekalni wszystkie zmienione i nowe pliki, które są śledzone przez system wersjonowania. W momencie dodania w poczekalni tworzona jest migawka pliku, która po zatwierdzeniu poleceniem `git commit` zostanie dopisana do nowej rewizji
* `git diff`
    * Pokazuje różnice między poczekalnią a ostatnią zatwierdzoną rewizją
* `git commit`
    * Zatwierdza zmiany zarejestrowane w poczekalni: tworzy nową rewizję w lokalnym repozytorium i dodaje do niej przygotowane w poczekalni migawki plików
* `git commit --amend`
    * Korekta. Scalenie zmian oczekujących aktualnie w poczekalni ze zmianami w ostatniej rewizji. W efekcie powstaje nowa rewizja, która tak jest podpinana, że zastępuje aktualną rewizję. Poza poprawkami w plikach można również poprawić nazwę i komentarz rewizji.
* `git push`
    * Wysyła nowe rewizje do repozytorium zdalnego (domyślnie jest to repozytorium o nazwie `origin`). Dodatkowo aktualizuje w zdalnym repozytorium pozycje wskaźników: HEAD i wskaźnika bieżącej gałęzi (domyślnie jest to gałęź master)
* `git pull`
    * Pobiera migawki z repozytorium zdalnego oraz pozycje wskaźników (głowa i bieżąca gałąź) z repozytorium zdalnego a następnie scala różnice z lokalnym repozytorium

Więcej informacji o poleceniach git wraz z dokładniejszym wyjaśnieniem w artykule: [Git: Wizualna ściąga](https://marklodato.github.io/visual-git-guide/index-pl.html) (tłumaczenie angielskiego artykułu: "A Visual Git Reference")

# Klienci GUI dla Git-a

Alternatywą dla standardowego klienta z linii poleceń są aplikacje graficzne. Do nauki Git-a zazwyczaj zalecane jest korzystanie z linii poleceń, aby dokładnie zrozumieć metodę działania. Z kolej narzędzia graficzne pozwalają le

# Repozytorium Git-a

Repozytorium Git-a zawiera zbiór rewizji, które składają się z migawek plików:
* **zbiór rewizji** to zbiór wersji historycznych zarejestrowanych plików, 
* rewizja = zbiór migawek
* migawka piku to pełna kopia danego pliku (nie jest to delta zmian!)

Zbiór migawek w danej rewizji zawiera:
* pełne kopie plików, które zostały zmienione oraz wszystkie nowe pliki 
* wskaźniki do wcześniejszej migawki plików, które nie uległy zmianie

W efekcie system Git ma możliwość natychmiastowego dostępu do dowolnej wersji repozytorium. O wiele prostsze staje się również rozgałęzianie i scalanie różnych wersji plików. Git można traktować jako bardzo wydajny systemem plików z możliwością optymalnego zapamiętania ich wcześniejszych wersji. Systemy wersjonowania kodu starszej generacji (takie jak Subversion i CVS) mają o wiele gorszą wydajność oraz są dużo trudniejsze i bardziej kłopotliwe w zarządzaniu.

# Struktura rewizji

**Identyfikator**. Rewizja jest jest unikalnie identyfikowana 40 znakowym kodem SHA-1 (20 bajtów zapisanych heksadecymalnie). Unikalność identyfikatora rewizji jest zapewniona nie tylko w ramach lokalnego repozytorium, ale również globalnie w ramach wielu repozytoriów. Dla łatwiejszego odwoływania się do rewizji w praktyce stosuje się 7-znakowy skrót (pierwsze 7 znaków z 40 znakowego skrótu SHA-1).

![Repozytorium Git](./resources/git01-repozytorium.png)

**Struktura**. Każda rewizja połączona jest z poprzednią wersją, a dokładniej to *nowsza* wersja wskazuje *starszą*. W efekcie możliwe jest aby jedna *starsza* rewizja była wskazywana równocześnie przez kilka *nowszych* rewizji. Taką sytuację nazywa się rozgałęzieniem.

Poza połączaniami rewizji strukturę budują również wskaźniki Git-a. Jest ich kilka rodzajów:

* **głowa (HEAD)** - aktualnie widoczna w katalogu roboczym rewizja. Głowa może wskazywać dowolną gałąź lub bezpośrednio którąś z rewizji. Każda zmiana (commit) powoduje utworzenie nowej rewizji i przesuniecie głowy

* **gałąź (branch)** - nazwany wskaźnik, który wskazuje dowolną rewizję w repozytorium. Gałąź aktualna to taka, którą wskazuje głowa. Przełączanie się miedzy gałęziami powoduje również aktualizację plików w katalogu roboczym. Jeśli głowa (HEAD) wskazuję gałąź to w momencie zmiany przesuwany jest ten wskaźnik gałęzi na nowo powstałą rewizję. Głowa nadal wskazuje na tą gałąź, czyli pośrednio zostanie "przesunięta".

* **gałąź główna (master)** - tworząc nowe repozytorium, automatycznie tworzona jest gałąź główna o nazwie master. Zazwyczaj wskazuje na aktualną zatwierdzoną wersję wersjonowanych dokumentów.

* **etykieta (tag)** - nazwany wskaźnik rewizji, w odróżnieniu od gałęzi nie przesuwa się w momencie wprowadzenia zmian, czyli stale wskazuje wybraną rewizję. Można ja wykorzystać to wskazania numeru wersji projektu.


# Zdalne repozytorium

Git jest rozproszonym systemem wersjonowania kodu źródłowego, czyli programista zazwyczaj korzysta ze swojej własnej kopii repozytorium głównego. Lokalne repozytorium jest w pełni autonomiczną kopią repozytorium Git-a. Dzięki takiemu rozwiązaniu możliwe jest zatwierdzanie zmian bez połączenia sieciowego (sieć lokalna lub sieć Internet). 



![Zdalne repozytorium](./resources/git02-zdalne.png)

Repozytorium lokalne tworzone jest na dwa sposoby: 
* poleceniem ```git init``` - powstaje puste repozytorium w katalogu, w którym wydano takie polecenie.
* poleceniem ```git clone [adres_repozytorium_zdalnego]``` - tworzone jest nowe repozytorium będące kopią zdalnego, w takiej sytuacji adres do repozytorium zdalnego zapamiętywany jest po skrótem, nazwanym domyślnie ```origin```.

Zmiany umieszczone w repozytorium lokalnym można w każdym momencie zsynchronizować z repozytorium zdalnym wydając poleceni ```git push```

Sprawdzenie listy zarejestrowanych zdalnych repozytoriów:

```sh
$ git remote -v

origin	https://github.com/bogdanpolak/MARS.git (fetch)
origin	https://github.com/bogdanpolak/MARS.git (push)
upstream	https://github.com/andrea-magni/MARS.git (fetch)
upstream	https://github.com/andrea-magni/MARS.git (push)
```

Rejestracja repozytorium:

```sh
$ git remote add xstream https://github.com/andrea-magni/MARS.git
```

# RAD Studio i GitHub

![Delphi i GitHub](./resources/git03-delphi-git.png)

Środowisko RAD Studio (Delphi i C++Builder) zawiera integrację z Git-em nazywaną VersionInsight. Rozszerzenie to pozwala na przeglądanie zmian oraz wydawanie kilku najprostszych poleceń git-a bezpośrednio ze środowiska IDE. W praktyce najlepiej sprawdza się w czasie rejestrowania zmian oraz dodawania plików do repozytorium lokalnego (polecenie `git add` i `git commit`).

Aby zacząć korzystać z tej integracji w RAD Studio konieczna jest konfiguracji opcji VersionInsight:

![](./resources/opcje-IDE-dla-Gita.png)


## Ignorowanie plików

Git sprawdza zawartość pliku `.gitignore`, który jest wykorzystywany w momencie rejestrowania zmian. Pomijane są wszystkie pliki zapisane w `.gitignore` (zapisujemy pełną nazwę pliku lub wzorzec do którego pasuje wiele plików). Ignorować można również katalogi.

**Pliki projektów**

W przypadku projektów RAD Studio poza plikami binarnymi, które łatwo jest wykluczyć trudności powodują pliki projektu (`*.dproj` lub `*.cbproj`) oraz pliki grupy projektów. Są to pliki XML, które są automatycznie zapisywane przez środowisko i programista nie ma kontroli nad ich formatem i zawartością. Niestety środowisko potrafi znacznie zmodyfikować taki plik przy drobnej zmianie. Dlatego warto usuwać ten plik z systemu wersjonowania, z którego korzysta kilku programistów. Jednak nie zawsze jest to możliwe.

Jeśli plik projektu musi być w repozytorium to warto zadbać o to, aby dodawać go tylko, gdy jest to konieczne, a nie przy każdej zmianie. Jednym z rozwiązań jest ręczne przełączanie flagi `Skip-worktree` dla tego pliku. Ustawienie tej flagi spowoduje pomijanie tego pliku, przy kolejnych rejestracjach zmian.

* Ustawienie flagi `Skip-worktree` 
```
git update-index --skip-worktree Project1.cbproj
```

## Praca grupowa i repozytoria zdalne

Typowym schematem pracy w repozytoriach OpenSource jest zgłaszanie zmian, które wprowadzamy najpierw w swoim zdalnym repozytorium projektowym (`origin`). Portale takie GitHub analizują różnice między repozytorium autorskim (źródłowym) a jego klonem (`fork`) i gdy w naszym sklonowanym repozytorium pojawiają się nowe rewizje to możemy w prosty sposób zgłosić żądnie aktualizacji (`pull request`).

![Diagram: schemat pracy z repozytoriami](./resources/github02-pull-request.png)

Nasze repozytorium zdalne domyślnie nazywane jest `origin` i tej nazwy warto się trzymać. Z kolei nadrzędne zdalne repozytorium autorskie nazywane jest w skrócie `upstream`.

Odwoływanie się do repozytorium autorskiego umieszczonego w chmurze możliwe jest za pomocą długie adresu URL. Wpisywanie tego adresu za każdym razem konieczne jest mało wygodne, dlatego definiujemy skrót do tego repozytorium, który nazwiemy `upstream`. Nowy skrót dodajemy poleceniem:

```
git remote add <nazwa-skrótu> <adres-url>
```
Na przykład:

```
git remote add upstream https://github.com/andrea-magni/MARS.git
```

Po zgłoszeniu żądania aktualizacji `pull request` autor przegląda zmiany i decyduje co z nimi zrobić: może poprosić o naniesienie poprawek lub sam dokonuje korekt. Takie poprawki mogą rozciągnąć się na kilka rewizji. Czasem są to ważne zmiany, a czasem drobne literówki. Na koniec autor decyduje w jaki sposób taki pakiet zmian "przenieść" do swojego głównego repozytorium. Mamy tutaj kilka strategi takiego przenoszenia. 

Zazwyczaj autorzy decydują się na scalenie zmian, czyli łączą wszystkie rewizje wchodzące w skład jednego żądania (`pull request`) w jedną, scaloną rewizję. W takim scenariuszu w repozytorium autora (`upstream`) powstaje nowa rewizja, której nie ma ani w moim repozytorium zdalnym (`origin`), ani lokalnym. Stąd konieczne jest pobranie zmian z repozytorium zdalnego `upstream` do naszego lokalnego repozytorium, scalenie różnic i aktualizacja naszego zdalnego repozytorium (`origin`).

Pobranie zmian z repozytorium zdalnego wykonujemy poleceniem:

```
git fetch <repo-url> master
``` 

Polecenie `git fetch` pobiera jedynie nowe migawki oraz nowe rewizje z repozytorium zdalnego i nie scala je z naszą lokalną rewizją bieżącą (`HEAD`). Dzięki temu możemy przeanalizować różnice i dopiero po upewnieniu się co do stanu zmian przełączyć głowę `HEAD` na aktualną wersję stworzoną przez autora.

Pełna procedura aktualizacji repozytorium lokalnego oraz repozytorium zdalnego `origin` na podstawie zmian w repozytorium zdalnym `upstream` wygląda następująco:

```sh
git fetch upstream master
git reset --hard upstream/master
git push --force
```

* Polecenie `git reset --hard` przenosi aktualną gałąź na pozycję `upstream/master` i modyfikuje wszystkie pliki w katalogu roboczym zmieniając je do stanu zgodnego z tą rewizją.
* Polecenie `git push --force` wymusza aktualizację zdalnego repozytorium, w efekcie znikną (będę nie widoczne) nasze drobne korekty i zastąpi je jedna scalona zmiana.



# Symulatory Git-a

Dwa przykłady z wielu (wystarczy poszukać):

1. Symulator z zadaniami oraz z wizualizacją w formie grafu
  * [Learning Git Branching](https://learngitbranching.js.org)
  * Ciekawe zadania pozwalające głębiej poznać pracę z gałęziami w Git-cie
  * Zadania w języku angielskim
  
2. Fajna wizualizacja na grafie do własnych eksperymentów
  * [Visualizing Git](http://git-school.github.io/visualizing-git/)
  * Dokładne odwzorowanie rewizji w Git-cie
  * Symulacja repozytorium lokalnego i zdalnego (origin)
