/**
 *
 */
function validateFunc() {
  alert("inside validateFunc !!");
  var element1=document.getElementById("bookname").value;
  var element2=document.getElementById("authorname").value;
  if(element1==null || element2==null || element1=="" || element2==""){
	  alert("Please Re-validate your Input!!");
	  return false;
  }
  return true;
}
function displayField(){
	var element1=document.getElementById("bookname");
	var element2=document.getElementById("authorname");
	var element3=document.getElementById("adddata");
	element1.setAttribute("type", "text");
	element2.setAttribute("type", "text");
	element3.setAttribute("type", "submit");

}
function setType(type,bookName){
	document.getElementById('actionType').value=type;
	document.getElementById('bookToAlter').value=bookName;
	var element4=document.getElementById("newBook");
	var element5=document.getElementById("updatefinal");
	element4.setAttribute("type","text");
	element5.setAttribute("type","submit");
}
function setType1(type){
	document.getElementById('actionType').value=type;
//	console.log(actionType);
}
function setType2(type,bookName){
	document.getElementById('actionType').value=type;
	document.getElementById('bookToAlter').value=bookName;
}
function validateFunc2(){
	alert("inside validateFunc2 !!");
	  var element6=document.getElementById("newBook").value;
//	  console.log(element6);
	  if(element6==null || element6==""){
		  alert("Please Re-v" +
		  		"Validate your Input!!");
		  return false;
	  }
	  return true;
}
