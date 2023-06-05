-- usando SELECTS -----------
-- Ordenacao
select * from clientes
order by nome;
-- ordenando por nome em atributos selecionados
select funcionarioID, nome, email, telefone from funcionarios
order by nome;
-- listar entre nomes
select nome from funcionarios where nome between 'Anna' and 'Fernado';
-- selecionando nome a partir da letra M
select * from fornecedores where nome like 'M%';
-- Ordenando Valor na tabela Pagamentos
select valor from pagamentos
order by valor;
-- Ordenando valores acima do solicitado
select valor from pagamentos
where valor > 1000 order by valor;
-- Selecionando lista sem um nome mencionado
select nome from funcionarios
where nome not like 'Fernado' order by nome DESC;

-- FUNCOES COM SELECT
-- count
-- selecionando quantos clientes foram cadastrados 
select COUNT(clienteID) as cpf from clientes;
-- selecionando quantidade de valores abaixo de 1000
select COUNT(pagamentosID) from pagamentos where valor < 1000;

-- informando a media dos valores na tabela de pagamentos
-- AVG
select AVG(valor) from pagamentos; 

-- somando os valores da tabela de pagamentos
-- SUM
select SUM(valor) from pagamentos;
-- somando quantidade de itens em estoque na tabela produtos
select SUM(estoque) from produtos;

-- informando o menor valor da tabela de pagamentos
-- MIN
select MIN(valor) from pagamentos;

-- Informando o maior valor da tabela de pagamentos
-- MAX
select MAX(valor) from pagamentos;

select * from estados;