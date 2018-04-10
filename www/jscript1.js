function reg()
{
	var name = document.getElementById("us").value
	var name1 = document.getElementById("p1").value
	var name2 = document.getElementById("p2").value
	var date1 = document.getElementById("d").value
	var usrtel = document.getElementById("p").value
	var email = document.getElementById("email").value
	//js work aavunnilla

	var mailformat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
	if (name == "") {
		alert("Please enter username!!");
		document.getElementById("name").focus();
		return false;
	}
		
	else if ( email == "" || email.match(mailformat)==false ) {
		alert("Please enter valid Email-ID !!");
		document.getElementById("email").focus();
		return false;
	}
	
	else if (name1 == "") {
		alert("Please enter password!!");
		document.getElementById("name1").focus();
		return false;
	}
	
	else if (date1 == "") {
		alert("Please enter city!!");
		document.getElementById("date1").focus();
		return false;
	}

	else if (usrtel == "") {
		alert("Please enter qualification!!");
		document.getElementById("usrtel").focus();
		return false;
	}

	else if (name1!=name2)
	{
		alert("Passwords do not match!!!!!, Re-enter.");
		document.getElementById("name1").focus();
		return false;
	}
	else
	{
		return true;
	}

}
function log()
{
	var user = document.getElementById("name").value
	var pwd = document.getElementById("name1").value
	var mailformat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
	if (user == "" || email.match(mailformat)==false ) {
		alert("Please enter valid username/Email-ID !!");
		document.getElementById("user").focus();
		return false;
	}
	else if (pwd == "") {
		alert("Please enter password!!");
		document.getElementById("pwd").focus();
		return false;
	}
	
	else
	{
		return true;
	}
}

