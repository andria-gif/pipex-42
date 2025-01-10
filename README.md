# pipex-42

## **Descrição Geral**
Este projeto simula o comportamento de pipelines no terminal Linux, permitindo redirecionar a entrada e saída entre comandos através de um pipe.

### **Compilação**
Para compilar o projeto, execute o comando:
```bash
gcc -Wall -Werror -Wextra -o pipex *.c
```

### **Execução**
O programa aceita os seguintes argumentos:
```bash
./pipex <file1> <cmd1> <cmd2> <file2>
```
- `file1`: Arquivo de entrada.
- `cmd1`: Primeiro comando a ser executado.
- `cmd2`: Segundo comando a ser executado.
- `file2`: Arquivo de saída.

#### **Exemplo de Teste**
```bash
./pipex input.txt "grep pattern" "wc -l" output.txt
```
- **Entrada:** `input.txt`.
- **Comandos:**
  - `grep pattern`.
  - `wc -l`.
- **Saída:** `output.txt`.

---

## **Estrutura do Código**

### **Funções Principais**

#### **1. main**
- Gerencia a execução geral do programa.
- Cria o pipe e dois processos filhos para executar os comandos.
- Fecha os descritores de arquivo no processo pai.

#### **2. son_process1**
- Responsável por:
  - Abrir o arquivo de entrada `file1`.
  - Redirecionar:
    - Entrada padrão (`STDIN_FILENO`) para `file1`.
    - Saída padrão (`STDOUT_FILENO`) para o lado de escrita do pipe.
  - Executar o comando `cmd1`.

#### **3. son_process2**
- Responsável por:
  - Abrir o arquivo de saída `file2`.
  - Redirecionar:
    - Entrada padrão (`STDIN_FILENO`) para o lado de leitura do pipe.
    - Saída padrão (`STDOUT_FILENO`) para `file2`.
  - Executar o comando `cmd2`.

#### **4. ft_open_file**
- Abre arquivos nos modos apropriados:
  - Somente leitura (`O_RDONLY`) para `file1`.
  - Escrita com truncamento/criação (`O_WRONLY | O_CREAT | O_TRUNC`) para `file2`.

#### **5. ft_exec**
- Executa um comando fornecido (`cmd`) com seus argumentos.
- Localiza o caminho do comando usando a variável `PATH`.

---

### **Fluxo de Dados**
1. O **processo pai** cria um **pipe** e dois processos filhos:
   - **Filho 1:** Lê de `file1`, executa `cmd1` e escreve no pipe.
   - **Filho 2:** Lê do pipe, executa `cmd2` e escreve em `file2`.
2. Cada filho usa `dup2` para redirecionar os descritores de arquivo:
   - Entrada padrão para leitura.
   - Saída padrão para escrita.

#### **Resumo Visual**
```text
 file1 --> [cmd1: son_process1] --> pipe --> [cmd2: son_process2] --> file2
```

---

## **Tratamento de Erros**
- **Mensagens de Erro:**
  - Exibidas com `perror`.
  - O programa encerra com `exit(EXIT_FAILURE)` em caso de erro.

- **Cenários Tratados:**
  1. Falha ao abrir arquivos.
  2. Erro ao criar o pipe.
  3. Erro ao criar processos com `fork`.
  4. Falha ao redirecionar descritores de arquivo (`dup2`).
  5. Comando não encontrado.

---

## **Exemplo de Execução**
```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```
### **Processo:**
1. **`son_process1`:**
   - Lê `input.txt`.
   - Executa `grep hello`.
   - Escreve a saída no pipe.
2. **`son_process2`:**
   - Lê do pipe.
   - Executa `wc -l`.
   - Escreve a saída em `output.txt`.

---

## **Notas Técnicas**
- **Chamada de Sistema Utilizadas:**
  - `pipe`: Cria um canal de comunicação.
  - `fork`: Cria novos processos.
  - `dup2`: Redireciona descritores de arquivo.
  - `execve`: Executa comandos.
  - `open`: Abre arquivos com permissões específicas.

- **Permissões de Arquivo:**
  - Arquivos criados usam permissões `0644` (leitura/escrita para o dono; leitura para grupo e outros).


