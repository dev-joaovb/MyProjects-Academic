function cadastrarRemedio(){
  
  var remedioName = document.getElementById("remedioName");
  var remedioReceita = document.getElementById("remedioReceita");
  var remedioQuantidade = document.getElementById("remedioQuantidade");
  var remedioDescricao = document.getElementById("remedioDescricao");
  var remedioFabricante = document.getElementById("remedioFabricante");
  var remedioValor = document.getElementById("remedioValor");

  var dados =  JSON.parse(localStorage.getItem("dadosRemedio"));

  if(dados == null){
    localStorage.setItem("dadosRemedio", "[]")
    dados = [];
  }
  
  
  var auxRegistro = {
    nome:       remedioName.value,
    receita:    remedioReceita.value,
    quantidade: remedioQuantidade.value,
    descricao:  remedioDescricao.value,
    fabricante: remedioFabricante.value,
    valor:      remedioValor.value
    
  }
  
  dados.push(auxRegistro);
  
  localStorage.setItem("dadosRemedio", JSON.stringify(dados));
  
  alert("Remedio cadastrado com sucesso.")
  
  remedioName.value = "";
  remedioReceita.value = "";
  remedioQuantidade.value = "";
  remedioDescricao.value = "";
  remedioFabricante.value = "";
  remedioValor.value = ""
  }