# 📚 Sistema CRUD de Gerenciamento Escolar em C

Este projeto é um sistema simples de gerenciamento de cadastros de alunos, desenvolvido em linguagem C. Ele implementa as operações básicas de **CRUD (Create, Read, Update, Delete)** utilizando vetores de `structs` e aplica a política de **Soft Delete** para preservação dos dados.

---

## 🛠️ Principais Funcionalidades

Este programa oferece as seguintes operações robustas:

* **Cadastro (Create):** Permite a inclusão de novos registros de alunos, com validação de entrada e inicialização do status como **ativo (1)**.
* **Consulta (Read):** Oferece visualização completa de todos os alunos **ativos** no sistema, ou consulta detalhada de um registro individual pelo número de cadastro.
* **Atualização (Update):** Permite modificar dados específicos (nome, idade, matrícula, etc.) de um aluno **ativo**, garantindo que registros inativos não possam ser alterados.
* **Exclusão Lógica (Soft Delete):** Altera o status do aluno para **inativo (0)** em vez de deletar o registro fisicamente, preservando o histórico.
* **Reativação:** Permite reverter a exclusão, ativando novamente um registro que estava inativo.
* **Relatório de Status:** O menu principal exibe a contagem atualizada de alunos **ativos** versus o **total de registros** existentes.

---

## ⚙️ Compilação e Execução

Para compilar e executar o projeto, você precisará ter o compilador **GCC** instalado no seu ambiente (Windows com MinGW/WSL, Linux ou macOS).

### 1. Salvar o Código

Salve todo o código-fonte (incluindo as `structs`, `main` e todas as funções) em um único arquivo chamado, por exemplo, `main.c`.

### 2. Compilar via Terminal

Abra o seu terminal (CMD, PowerShell, WSL, ou Terminal Linux/macOS) e execute o comando de compilação:

```bash
gcc main.c -o duarte_cadastro_alunos
./duarte_cadastro_alunos
```