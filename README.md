# Introdução a Técnicas de Programação - Unidade 1
**Aluno**: Felipe Augusto de Lima Duarte 

**Matrícula**: 20250025417

**Período**: 2025.2 

## 📁 Estrutura do Projeto
 - `projeto/`: Projeto principal da unidade 
 - `listas/`: Soluções das listas de exercícios 
 - `README.md`: Este arquivo 

## 🚀 Projeto: Duarte Cadastro Escolar

**Descrição**: Este projeto é um **Sistema de Gestão Escolar** em C, que permite realizar as operações básicas de **Criação, Consulta, Atualização e Exclusão (CRUD)** de registros de alunos via terminal. 

**Repositório**: https://github.com/felipe-duarte-dev/felipe-duarte-itp-2025-2

**Vídeo de Demonstração**: *Em Breve* 

### Funcionalidades Implementadas:

* **Cadastro (Create):** Permite a inclusão de novos alunos, coletando informações como nome, idade, série escolar e matrícula.
* **Consulta (Read):** Oferece visualização completa de todos os alunos **ativos** no sistema, ou consulta detalhada de um registro individual pelo número de cadastro.
* **Atualização (Update):** Permite alterar dados específicos (nome, idade, matrícula, etc.) de um aluno **ativo** após sua localização pelo índice.
* **Exclusão Lógica (Soft Delete):** Inativa um cadastro em vez de deletá-lo fisicamente, preservando o histórico de dados.
* **Reativação:** Permite reverter um registro inativo, reativando o cadastro do aluno.
* **Relatório de Status:** Exibe a contagem atualizada de alunos **ativos** versus o **total de registros** existentes no sistema.

### Conceitos da U1 Aplicados:

### Estruturas Condicionais:

* **Validação de Entrada (`if`, `else`):** Usadas para verificar a validade das opções de menu e, crucialmente, garantir que os **índices** de cadastro não excedam os limites do vetor (segurança de memória).
* **Controle do Soft Delete (`if`):** Aplicadas em `consultar_alunos` (para filtrar alunos inativos com o comando **`continue`**) e em `deletar_aluno` (para verificar e alternar o status `ativo`).
* **Menu Principal e Submenus (`switch`):** Utilizado para direcionar o fluxo do programa para a função ou ação correta com base na escolha do usuário.

### Estruturas de Repetição

* **Menus Interativos (`do-while`):** Usado nas funções `main`, `consultar_alunos` e `alterar_aluno` para garantir que o menu fosse exibido e repetido até que o usuário escolhesse a opção de sair.
* **Iteração de Dados (`for`):** Aplicado em `consultar_alunos` e na função auxiliar de contagem para **percorrer o vetor de `structs`**, inspecionando o status `ativo` de cada aluno.

### Vetores

* **Lista Principal de Dados:** O vetor (`Aluno lista_alunos[100]`) atua como o **banco de dados** principal, armazenando até 100 registros do tipo `struct Aluno`.
* **Strings:** Os nomes (`char nome[50]`) e matrículas (`char matricula[12]`) são implementados como vetores de caracteres.

### Funções

1.  **`main`:** Gerencia o menu principal e o fluxo de chamadas das funções CRUD.
2.  **`limpar_buffer`:** Garante a leitura correta de entradas de dados (após `scanf`).
3.  **`cadastros_ativos`:** Calcula e retorna o número de alunos com o status `ativo == 1`.
4.  **`cadastro_aluno` (Create):** Insere novos registros no vetor.
5.  **`consultar_alunos` (Read):** Exibe a lista de alunos, filtrando apenas os **ativos**.
6.  **`alterar_aluno` (Update):** Modifica os dados de um aluno **ativo** localizado pelo índice.
7.  **`deletar_aluno` (Soft Delete/Reativar):** Alterna o status `ativo` de um registro.

## 📚 Listas de Exercícios 

### Semana 2 - Variáveis, Tipos e Operadores:
- ✅ Problema 1: Calculadora de IMC 
- ✅ Problema 2: Conversão de temperatura 
- ✅ Problema 3: Cálculo de juros compostos
- ✅ Problema 4: Operações aritméticas básicas

### Semana 3 - Condicionais:
- ✅ Problema 1: Classificação de IMC 
- ✅ Problema 2: Calculadora de energia elétrica 
- ✅ Problema 3: Sistema de notas 
- ✅ Problema 4: Pedra, papel, tesoura 
- ✅ Problema 5: Calculadora de desconto progressivo
- ✅ Problema 6: Diagnóstico médico simples 
- ✅ Problema 7: Sistema de equações do 2º grau 
- ✅ Problema 8: Validador de triângulos 

### Semana 4A - Repetições:
- ✅ Problema 1: Dobrar folha 
- ✅ Problema 2: Homem Aranha 
- ✅ Problema 3: Números colegas 
- ✅ Problema 4: Jogo de dardos 

### Semana 4B - Análise e Padrões:
- ✅ Questões 1-4: Análise de código 
- ✅ Questões 5-11: Implementações 

### Semana 5 - Funções (Parte 1):
- ✅ Problema 1: Horários das rondas 
- ✅ Problema 2: Primos triplos 
- ✅ Problema 3: Pousando a sonda espacial 

### Semana 6 - Vetores: 
- ✅ Problema 1: MEC - Correção ENEM 
- ✅ Problema 2: Álbum de figurinhas  
- ✅ Problema 3: A construção da ponte 
- ✅ Problema 4: Em busca do tesouro perdido 

## 🎯 Principais Aprendizados 

- Conceitos fundamentais de programação em C
- Aplicação de conceitos matemáticos em programação
- Resolução de problemas em programação
- Git e Github
- Padrão CRUD

## 🔧 Ambiente de Desenvolvimento
- **SO**: Windows 
- **Compilador**: GCC versão [6.3.0] 
- **Editor**: VSCode