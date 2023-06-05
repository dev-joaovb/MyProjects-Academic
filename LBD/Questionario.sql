-- Listar todos os produtos com as respectivas descrições, unidades e valores unitários, obtendo o seguinte resultado:

-- Listar todo o conteúdo de vendedor, obtendo o seguinte resultado, usando *:

-- Listar da tabela CLIENTE o CNPJ, o nome do cliente e seu endereço, obtendo o seguinte resultado:

-- Listar todas as cidades em que há clientes

-- Listar todas as cidades e estados em que há clientes

-- Quais são os clientes que moram em Niterói?

-- Listar os produtos que tenham unidade igual a ‘M’ e valor unitário igual a R$ 1,05 da tabela produto:

-- Listar o código, a descrição e o valor unitario dos produtos que tenham o valor unitário na faixa de R$ 0,32 até R$ 2,00:

-- Listar oo código, a descrição e o valor unitario dos produtos que NÃO tenham o valor unitário na faixa de R$ 0,32 até R$ 2,00:
 
-- Listar os nomes entre Ana e Jorge

-- Between: https://www.w3schools.com/sql/sql_between.asp
-- Listar Listar os vendedores com faixas de comissão A ou B

-- Listar todos os clientes SEM Inscrição Estadual (IE)

-- Listar todos os clientes COM Inscrição Estadual (IE)

-- Listar apenas os dois primeiros vendedores

-- https://www.w3schools.com/sql/sql_top.asp: O MySQL suporta a cláusula LIMIT para selecionar um número limitado de registros. Pode ser útil em grandes tabelas com milhares de registros.
/* 
LIKE: 
Existem dois curingas:
%   o sinal de porcentagem representa zero, um ou vários caracteres
_   o sublinhado representa um único caractere
https://www.w3schools.com/sql/sql_like.asp
*/
-- Listar todos os produtos que tenham o seu nome começando por Q:

-- Listar os vendedores que não começam por ‘Jo’:

-- Listar todos os produtos cujo nome termina com 's';
                                                  -- no banco original não há s
-- Listar os produtos que contenham as letras "inh"

-- Listar os chocolates e valores 
                                                  -- no banco original não há chocolate amargo e ao leite
-- Listar os vendedores cuja segunda letra do nome seja 'a'


-- ORDER BY
-- Listar todos os vendedores ordenados por nome
                                       -- por default, o order by é ASC
-- Listar todos os vendedores ordenados por nome de forma descrescente

-- Listar todos os vendedores ordenados por nome e salario 

-- Listar todos os clientes com seus estados, sendo que o estado deverá ser ordenado em ordem crescente e o nome por ordem descrescente

-- Listar todos os vendedores que ganham MENOS de 1000 reais e apresentar em ordem crescente

-- Listar os vendedores que não começam por ‘Jo’ e apresentar ordenado de forma descrescente


-- FUNÇÕES COUNT(), AVG(), SUM(), MIN() e MAX()
-- Informe quantos clientes foram cadastrados
                                             -- Valores NULL não são contados 
-- Informe quantos produtos tem valor unitário abaixo de 0.50 centavos

-- Informe a média de salario dos vendedores
                                              -- Valores null são ignorados
-- Informe a média de valores unitarios dos produtos vendidos a M

-- Somar o valor de todos os salários

-- Somar o valor dos salarios da comissão A

-- Somar a quantidade de itens de pedidos

-- Informe o menor salario do vendedores

-- Informe o maior salario do vendedores

-- Informe o maior salario do vendedores da faixa de comissão B

-- Listar os nomes entre Ana e Jorge, ordenado de forma descrescente

 -- MySQL Functions: https://www.w3schools.com/sql/sql_ref_mysql.asp  
 
 -- COLUNAS CALCULADAS
 -- Mostrar o novo salário fixo dos vendedores, de faixa de comissão ‘C’, calculado com base no reajuste de 75% 
 -- acrescido de R$ 120,00 de bonificação. Ordenar pelo nome do vendedor

 
 -- GROUP BY
 -- Informe o número de clientes por Estado

-- Informe a média salarial por faixa de comissão

-- Informe a média salarial por faixa de comissão ordenado de forma descrescente por valor



-- HAVING
-- Informe a média salarial por faixa de comissão apenas das faixas com ganho acima de 2000

-- Informe a média salarial por faixa de comissão apenas das faixas com ganho acima de 2000 ordenado de forma descrescente por valor

-- INNER JOIN
-- Listar tudo

-- Listar todos os dados dos pedidos feitos por clientes


-- Listar os pedidos com seus respectivos vendedores


-- Listar o numero do pedido, o código do produto e a quantidade dos itens do pedido com a quantidade maior a 35 da tabela item de pedido


-- Listar os pedidos com seus respectivos clientes e vendedores


-- Litar a quantidade de itens vendidos por produto ordenados de forma crescente


-- JOIN
-- Listar todos os pedidos realizados, exibindo o nome dos clientes
-- Listar todos os pedidos realizados, exibindo o nome dos vendedores
-- Listar todos os pedidos realizados, exibindo o nome dos vendedores e clientes, ordenados por prazo de entrega
-- Listar o id e prazo de entrega dos pedidos realizados pela cliente 'Susana', incluindo o nome do vendedor

-- Listar o prazo_entrega mínima para cada cliente, apresentando nome do cliente (agrupado), ordenados por prazo máximo

-- Listar os clientes e vendedores com prazo de entrega entre 10 e 20 dias e ordene por prazo de entrega. O nome do campo deve ser alterado para nomeCliente e nomeVendedor


-- Listar cliente e média de prazo para entrega, considerando apenas os clientes com prazo acima de 10 dia 
-- Ao final, apresente somente os clientes cuja média é superior a 15 dias 
-- Ordene por prazo máximo


-- Listar os nomes dos produtos com quantidade somada, 
-- porém, considerando apenas os itens com quantidade inferior a 30.
-- Ao final, apresente apenas os itens cuja soma é superior a 40


-- Listar o nome do cliente, nome do vendedor, o id do pedido e os produtos comprados. Ordenar por cliente. 


-- Listar os nomes dos clientes que compraram 'Vinho'
-- Listar os nomes dos vendedores que venderam 'Vinho'
-- Listar qual a quantidade de 'Vinho' vendida pelos vendedores, ordenar por quantidade. 
-- Listar os pedidos, com o nome dos produtos, mas também os produtos que não constam da lista de pedidos