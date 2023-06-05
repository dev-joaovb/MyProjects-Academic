create database vendasPecasAutomotivas;
use vendasPecasAutomotivas;

create table Clientes (
clienteID INT NOT NULL, /* CHAVE PRIMARIA */
nome VARCHAR(100) NOT NULL,
cpf CHAR(11) NOT NULL,
email VARCHAR(30) NOT NULL,
celular VARCHAR(11),
cidadeId INT,  /* Chave estrangeira*/
observacao VARCHAR(150),
cnpj CHAR(14) NOT NULL,
senha VARCHAR(10) NOT NULL,
PRIMARY KEY(clienteID)
);

create table Recebimentos (
recebimentoID INT NOT NULL, /* CAHVE PRIMARIA */
valor DECIMAL(10,2),
dataVencimento DATETIME,
desconto DECIMAL(10,2),
juros DECIMAL(10,2),
dataPagamento DATETIME,
valorPago DECIMAL(10,2),
situacao VARCHAR(100),
planoContaID INT, /* CAHVE ESTRANGEIRA */
clientesID INT, /* CAHVE ESTRANGEIRA */
cobrancaID INT, /* CAHVE ESTRANGEIRA */
observacao VARCHAR(150),
PRIMARY KEY(recebimentoID)
);

create table Cidades (
cidadesID INT NOT NULL, /* CAHVE PRIMARIA */
nome VARCHAR(50) NOT NULL,
estadosID INT, /* CAHVE ESTRANGEIRA */
PRIMARY KEY(cidadesID)
);

create table estados (
estadosID INT NOT NULL, /* CAHVE PRIMARIA */
nome VARCHAR(50) NOT NULL,
uf CHAR(2) NOT NULL,
PRIMARY KEY(estadosID)
);

create table cargos (
cargoID INT NOT NULL, /* CAHVE PRIMARIA */
nome VARCHAR(50) NOT NULL,
salarioBase DECIMAL(10,2) NOT NULL,
situacao VARCHAR(100),
PRIMARY KEY(cargoID)
);

create table permissao (
permissaoID INT NOT NULL, /* CAHVE PRIMARIA */
permissao VARCHAR(50),
PRIMARY KEY(permissaoID)
);

create table funcionarios (
funcionarioID INT NOT NULL, /* CAHVE PRIMARIA */
nome VARCHAR(50) NOT NULL,
sexo ENUM ('M', 'F') NOT NULL,
email VARCHAR(20) NOT NULL,
telefone VARCHAR(11),
cidadeID INT, /* CAHVE ESTRANGEIRA */
dataAdmissao DATETIME,
dataDemissao DATETIME,
cargoID INT, /* CAHVE ESTRANGEIRA */
login VARCHAR(50) NOT NULL,
senha VARCHAR(10) NOT NULL,
situacao VARCHAR(100),
observacao VARCHAR(150),
PRIMARY KEY(funcionarioID)
);

create table funcionarioPermissao (
funcionarioPermissaoID INT NOT NULL, /* CAHVE PRIMARIA */
permissaoID INT, /* CAHVE ESTRANGEIRA */
funcionarioID INT, /* CAHVE ESTRANGEIRA */
PRIMARY KEY(funcionarioPermissaoID)
);

create table cobrancas (
cobrancasID INT NOT NULL, /* CAHVE PRIMARIA */
nome VARCHAR(50) NOT NULL,
situacao VARCHAR(100),
PRIMARY KEY(cobrancasID)
);

create table planoContas (
planoContasID INT NOT NULL, /* CAHVE PRIMARIA */
nome VARCHAR(50) NOT NULL,
codigo VARCHAR(20),
tipo CHAR(1),
situacao VARCHAR(100),
PRIMARY KEY(planoContasID)
);

create table pagamentos (
pagamentosID INT NOT NULL, /* CAHVE PRIMARIA */
valor DECIMAL(10,2),
dataVencimento DATETIME,
desconto DECIMAL(10,2),
juros DECIMAL(10,2),
dataPagamento DATETIME,
valorPago DECIMAL(10,2),
situacao VARCHAR(100),
funcionarioID INT, /* CAHVE ESTRANGEIRA */
fornecedorID INT, /* CAHVE ESTRANGEIRA */
planoContasID INT, /* CAHVE ESTRANGEIRA */
cobrancaID INT, /* CAHVE ESTRANGEIRA */
observacao VARCHAR(150),
PRIMARY KEY(pagamentosID)
);

create table tipoFornecedores (
tipoFornecedorID INT NOT NULL, /* CAHVE PRIMARIA */
nome VARCHAR(50) NOT NULL,
situacao VARCHAR(100),
PRIMARY KEY(tipoFornecedorID)
);

create table fornecedores (
fornecedoresID INT NOT NULL, /* CAHVE PRIMARIA */
nome VARCHAR(50) NOT NULL,
cnpj CHAR(14) NOT NULL,
cidadeID INT, /* CAHVE ESTRANGEIRA */
email VARCHAR(20) NOT NULL,
telefone VARCHAR(11),
tipoFornecedorID INT, /* CAHVE ESTRANGEIRA */
situacao VARCHAR(100),
observacao VARCHAR(150),
PRIMARY KEY(fornecedoresID)
);

create table seguros (
segurosID INT NOT NULL, /* CAHVE PRIMARIA */
nome VARCHAR(50) NOT NULL,
valor DECIMAL(10,2) NOT NULL,
descricao VARCHAR(100),
fornecedorID INT, /* CAHVE ESTRANGEIRA */
situacao VARCHAR(100),
PRIMARY KEY(segurosID)
);

create table produtos (
produtosID INT NOT NULL, /* CAHVE PRIMARIA */
nome VARCHAR(50) NOT NULL,
estoque INT NOT NULL,
valor DECIMAL(10,2) NOT NULL,
observacao VARCHAR(150),
fornecedorID INT, /* CAHVE ESTRANGEIRA */
PRIMARY KEY(produtosID)
);

create table vendas (
vendasID INT NOT NULL, /* CAHVE PRIMARIA */
produtosID INT, /* CAHVE ESTRANGEIRA */
clienteID INT, /* CAHVE ESTRANGEIRA */
quantidadeVenda INT,
PRIMARY KEY(vendasID)
);

create table notaFiscal (
notaFiscalID INT NOT NULL, /* CAHVE PRIMARIA */
produtoID INT, /* CAHVE ESTRANGEIRA */
clienteID INT, /* CAHVE ESTRANGEIRA */
PRIMARY KEY(notaFiscalID)
);