function cadastroUsuario(){
  
  var usuarioNome = document.getElementById("usuarioNome");
  var usuarioClient = document.getElementById("usuarioClient");
  var EnderecoUsuario = document.getElementById("EnderecoUsuario");
  var documentoUsuario = document.getElementById("documentoUsuario");
  var estadoClient = document.getElementById("estadoClient");
  var cidadeClient = document.getElementById("cidadeClient");
  var generoUsuario = document.getElementById("generoUsuario");
  var pass = document.getElementById("pass");
  var nascimento = document.getElementById("nascimento");
  var passConfirm = document.getElementById("passConfirm")

  var dados =  JSON.parse(localStorage.getItem("dadosClient"));

  if(dados == null){
    localStorage.setItem("dadosClient", "[]")
    dados = [];
  }
  
  
  var auxRegistro = {
    nome:               usuarioNome.value,
    usuario:            usuarioClient.value,
    endereco:           EnderecoUsuario.value,
    documento:          documentoUsuario.value,
    Estado:             estadoClient.value,
    cidade:             cidadeClient.value,
    Genero:             generoUsuario.value,
    senha:              pass.value,
    dataNascimento:     nascimento .value,
    confirmarSenha:     passConfirm .value
    
  }
  
  dados.push(auxRegistro);
  
  localStorage.setItem("dadosClient", JSON.stringify(dados));
  
  alert("Cadastro realizado com sucesso!")
  
  usuarioNome.value = "";
  usuarioClient.value = "";
  EnderecoUsuario.value = "";
  documentoUsuario.value = "";
  estadoClient.value = "";
  cidadeClient.value = "";
  generoUsuario.value = "";
  pass.value = "";
  nascimento .value = "";
  passConfirm .value = ""
  }


  function populateUFs(){
    const ufselect = document.querySelector("select[name=uf]")
    fetch("https://servicodados.ibge.gov.br/api/v1/localidades/estados")
    .then(res=> res.json())
    .then(states =>{
        for(const state of states){
            ufselect.innerHTML += `<option value="${state.id}">${state.nome}</option>`
        }     
    } )
}

populateUFs()


function getCities(event){
    const citySelect = document.querySelector("[name=city]")
    const stateInput = document.querySelector("[name=state]")

    const ufValue = event.target.value

    const indexOfSelectedState = event.target.selectedIndex
    stateInput.value = event.target.options[indexOfSelectedState].text
    const url = `https://servicodados.ibge.gov.br/api/v1/localidades/estados/${ufValue}/municipios`
   
    citySelect.innerHTML = "<option value>Selecione sua cidade</option>"
    citySelect.disabled = true 

    fetch(url)
    .then( res => res.json())
    .then( cities => {

        for(const city of cities){
            citySelect.innerHTML += `<option value="${city.nome}">${city.nome} </option>`
        }
        citySelect.disabled  = false 
    } )
}

document
.querySelector("select[name=uf]")
.addEventListener("change", getCities)



const itemsToCollect = document.querySelectorAll(".items-grid li")

for(const item of itemsToCollect){
    item.addEventListener("click", handleSelectedItem)
}

const collectedItems = document.querySelector("input[name=items]")
let selectedItems = []

function handleSelectedItem(event){
    const itemLi = event.target

    itemLi.classList.toggle("selected")

    const itemId = itemLi.dataset.id

    const alreadySelected = selectedItems.findIndex( item => {
        const itemFound = item == itemId
        return itemFound
    })

    if(alreadySelected>=0){
        const filteredItems = selectedItems.filter( item => {
            const itemIsDifferent = item != itemId
             return itemIsDifferent
        })
        selectedItems = filteredItems
    }else {
        selectedItems.push(itemId)
    }

    collectedItems.value = selectedItems
}