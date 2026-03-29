@echo off
echo =======================================================
echo Compilando Projeto de Captacao de Clientes...
echo =======================================================
gcc -Wall -Wextra -std=c99 cliente.c lista_dupla.c fila.c pilha.c interface.c main.c -o sistema_captacao.exe
if %ERRORLEVEL% EQU 0 (
    echo [SUCESSO] Compilacao Concluida sem Erros Criticos!
    echo Para executar use o comando: sistema_captacao.exe
) else (
    echo [ERRO] Ocorreu um problema ao compilar. Verifique os avisos acima.
)
pause
