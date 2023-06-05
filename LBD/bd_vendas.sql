drop database if exists vendas; -- excluir database

create database if not exists vendas
default character set utf8 -- uft8 (8-bit Unicode Transformation Format - Pode representar qualquer caracter universal padrão do Unicode, sendo também compatível com o ASCII)
default collate utf8_general_ci;

use vendas;-- selecionar banco de dados
/*
Outros comandos:
show database; -- lista os banco de dados criados
show tables;  -- lista as tabelas do database
describe ou desc "nome da tabela"; -- descreve os itens da tabela
*/

CREATE TABLE IF NOT EXISTS clientes ( -- criar tabela
    id INT NOT NULL,
    nome VARCHAR(100) NOT NULL,
    endereco VARCHAR(200),
    cidade VARCHAR(50),
    cep CHAR(8),
    uf CHAR(2),
    cnpj VARCHAR(20) NOT NULL UNIQUE,
    ie varchar (30),
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS vendedores (
    id INT NOT NULL,
    nome VARCHAR(100) NOT NULL,
    salario DECIMAL(7 , 2 ) NOT NULL,
    faixa_comissao ENUM('A', 'B', 'C'),
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS pedidos (
    id INT NOT NULL,
    prazo_entrega INT UNSIGNED NOT NULL,
    id_cliente INT NOT NULL,
    id_vendedor INT NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (id_cliente)
        REFERENCES clientes (id),
    FOREIGN KEY (id_vendedor)
        REFERENCES vendedores (id)
);

CREATE TABLE IF NOT EXISTS produtos (
    id INT NOT NULL,
    unidade VARCHAR(5) NOT NULL,
    descricao VARCHAR(100) NOT NULL UNIQUE,
    valor_unitario DECIMAL(4 , 2 ),
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS itens_pedido (
    id_pedido INT NOT NULL,
    id_produto INT NOT NULL,
    quantidade INT UNSIGNED NOT NULL,
    PRIMARY KEY (id_pedido , id_produto), -- chave primária composta  
    FOREIGN KEY (id_pedido)
        REFERENCES pedidos (id),
    FOREIGN KEY (id_produto)
        REFERENCES produtos (id)
);

INSERT INTO clientes VALUES 
(720, "Ana" , "Rua 17 n. 19", "Niteroi", 24358310, "RJ", 12113231000134, 2134),
(870, "Flavio" , "Av. Pres. Vargas 10", "Sao Paulo", 2276393, "SP", 2253412693879, 4631),
(110, "Jorge" , "Rua Caiapo 13", "Curitiba", 30078500, "PR", 1451276498349, NULL),
(222, "Lucia" , "Rua Itabira 123 Loja 9", "Belo Horizonte", 2212439, "MG", 2831521393488, 2985),
(830, "Mauricio" , "Av. Paulista 1236 sl 2345", "Sao Paulo", 3012683, "SP", 3281698574656, 9343),
(130, "Edmar" , "Rua da Praia sn", "Salvador", 30079300, "BA", 234632842349, 7121),
(410, "Rodolfo" , "Largo da Lapa 27 sobrado", "Rio de Janeiro", 30078900, "RJ", 1283512823469, 7431),
(20, "Beth" , "Av. Climerio 45", "Sao Paulo", 25679300, "SP", 3248512673268, 9280),
(157, "Paulo" , "Tv, Moraes c/3", "Londrina", NULL, "PR", 328482233242, 1923),
(180, "Livio", "Av. Beira Mar n. 1256", "Florianopolis", 30077500, "SC", 1273657123474,NULL),
(260, "Susana", "Rua Lopes Mendes 12", "Niteroi", 30046500, "RJ", 217635712329, 2530),
(290, "Renato", "Rua Meireles 123 bl.2 sl. 345", "Sao Paulo", 30225900, "SP", 1327657112314, 1820),
(390, "Sebastiao", "Rua da Igreja 10", "Uberaba", 30438700, "MG",  321765472133, 9071),
(234, "Jose", "Quadra 3 bl. 3 st. 1003", "Brasilia", 22841650, "DF", 2176357612323, 293);

INSERT INTO vendedores VALUES 
(209, "José", 1800, 'C'),
(111, "Carlos", 2490, 'A'),
(11, "João", 2780, 'C'),
(240, "Antônio", 9500, 'C'),
(720, "Felipe", 4600, 'A'),
(213, "Jonas", 2300, 'A'),
(101, "João", 2650, 'C'),
(310, "Josias", 870, 'B'),
(250, "Maurício", 2930, 'B');

INSERT INTO produtos VALUES 
(25, "Kg", "Queijo", 0.97),
(31, "BAR", "Chocolate", 0.87),
(78, "L", "Vinho", 2),
(22, "M", "Linho", 0.11),
(30, "SAC", "Açúcar", 0.3),
(53, "M", "Linha", 1.8),
(13, "G", "Ouro", 6.18),
(45, "M", "Madeira", 0.25),
(87, "M", "Cano", 1.97),
(77, "M", "Papel", 1.05);

INSERT INTO pedidos VALUES
(121,20,410,209),
(97,20,720,101),
(101,15,720,101),
(137,20,720,720),
(148,20,720,101),
(189,15,870,213),
(104,30,110,101),
(203,30,830,250),
(98,20,410,209),
(143,30,20,111),
(105,15,180,240),
(111,20,260,240),
(103,20,260,11),
(91,20,260,11),
(138,20,260,11),
(108,15,290,310),
(119,30,390,250),
(127,10,410,11);

INSERT INTO itens_pedido VALUES 
(97, 22, 31),
(98, 25, 77),
(101, 30, 31),
(103, 31, 78),
(104, 45, 13),
(105, 53, 77),
(108, 77, 45),
(111, 78, 31),
(119, 87, 77),
(121, 13, 25),
(127, 22, 78),
(137, 25, 53),
(138, 30, 31),
(143, 31, 78),
(148, 45, 31),
(189, 53, 78),
(203, 77, 78),
(91, 78, 25),
(97, 87, 78),
(98, 13, 53),
(101, 22, 77),
(103, 13, 22),
(104, 30, 77),
(105, 31, 53),
(108, 45, 13),
(119, 13, 77),
(121, 53, 13),
(127, 13, 22),
(137, 45, 53),
(138, 13, 13);