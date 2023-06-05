DROP TABLE itens_pedido; /* excluir tabela */

TRUNCATE TABLE itens_pedido; /* excluir conteudo da tabela */

ALTER TABLE clientes
ADD email VARCHAR(100) UNIQUE;

ALTER TABLE clientes
DROP sexo;

ALTER TABLE clientes
ADD sexo ENUM ('F', 'M');

ALTER TABLE clientes
MODIFY endereco VARCHAR(200);

