-- Usando o Union
-- Unindo Tabelas
SELECT P.produtoID, P.nome FROM produtos P
union
SELECT F.fornecedorID, F.nome FROM fornecedores F;
-- Organizando tabelas
SELECT P.produtoID, P.nome, 'PRODUTOS' as TIPO FROM produtos P
union
SELECT F.fornecedorID, F.nome, 'FORNECEDOR' as TIPO FROM fornecedores F
ORDER BY TIPO;

-- Usando o Distinct localizar registros unicos
 SELECT DISTINCT uf FROM vendas.clientes
WHERE uf = 'SP' OR uf = 'RJ';

-- Usando o Group By para organizar uma tabela de produtos
select P.valor as VALOR, P.estoque as ESTOQUE from produtos P
GROUP BY P.valor, P.estoque;
-- Adicionando estoque
select P.valor as VALOR, P.estoque, SUM(P.estoque+1) as ESTOQUE_ATUALIZADO from produtos P
GROUP BY P.valor, P.estoque;

-- Alterando linhas com UPDATE
-- Usando o UPDATE na tabela Cidades mudando Rio Branco para Rio de Janeiro
UPDATE cidades
set nome = 'Rio de Janeiro'
Where cidadeID = 1;
select * from cidades; -- para confirmar se alterou os dados
-- Atualizando salario
UPDATE cargos
set salarioBase = '6500,00'
where cargoID = 3; 
select * from cargos;

-- Usando o Trigger na tabela de produtos
delimiter $
create trigger baixaEstoque
after insert on produtos
for each row
begin
	update vendas
    set quatidadeVenda = quatidadeVenda - new.estoque
    where vendaID = new.produtoID;
end$

-- Usando o PROCEDURE
delimiter $$
create procedure pr_baixaEstoque(
in nCodigo int,
in nQuantidade decimal(10, 2)
)
begin
	update produtos
    set produto.estoque = produto.estoque - nQuantidade
    where produto.produtoID = nCodigo;
end$$
START TRANSACTION;
	delete from planoContas
    where planoContasID = 1;
    limit 1;
    insert into planoContas(planoContasID, nome, codigo, tipo, situacao)
		values(1, 'Valdemar', '44', 'E', 'Inativo');
	select * from planocontas;
ROLLBACK;