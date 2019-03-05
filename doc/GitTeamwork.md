# Repozytorium Git

# Materiały związane w repozytorim Git

1. Konfiguracja klienta Git (linia poleceń) `GitConfigure.md` [zobacz](./GitConfigure.md).
1. Artykuł wprowadzający `GitLearn.md` [zobacz](./GitLearn.md).
1. Artykuł praca z gałęziami w Git `GitWorkingWithBranches.md` [zobacz](./GitWorkingWithBranches.md)

***

# Konfiguracja Git

1. Pobranie i instalacja Git dla Windows
    * https://git-scm.com/download/win
	* (opcja) Manager autentykacji dla Git Windows, [więcej informacji ...](https://github.com/Microsoft/Git-Credential-Manager-for-Windows)
2. Stworzenie konfiguracji z danymi użytkownika:
	* Proszę wpisać swoje dane
	```sh
	git config --global user.email "you@example.com"
	git config --global user.name "Your Name"
	```
3. Dodanie aliasów do analizy historii  w formie drzewa
	* Modyfikacja pliku pliku konfiguracyjnego `.gitconfig` (lokalizacja: `C:\Users\{{użytkownik}}`)
	```
	[alias]
		graph1 = log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold green)(%ar)%C(reset) %C(white)%s%C(reset) %C(dim white)- %an%C(reset)%C(bold yellow)%d%C(reset)' --all
		graph2 = log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold cyan)%aD%C(reset) %C(bold green)(%ar)%C(reset)%C(bold yellow)%d%C(reset)%n''          %C(white)%s%C(reset) %C(dim white)- %an%C(reset)' --all
		lg = !"git graph1"
	```
4. Zmiana edytora
    * Klasyczny notatnik - Notepad
    ```sh
    git config --global core.editor C:\Windows\notepad.exe
    ```
    * Notepad++
    ```sh
    git config --global core.editor "'C:/Program Files (x86)/Notepad++/notepad++.exe' -multiInst -notabbar -nosession -noPlugin"
    ```

