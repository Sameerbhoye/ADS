function validate(){
    var name=document.getElementById("uname").value;
    if(name==""){
      return alert('Enter username ! ');
    }
    name=document.getElementById("pass").value;
    if(name==""){
      return alert('Enter password ! ');
    }
    name=document.getElementById("email").value;
    if(name==""){
      return alert('Enter Email ! ');
    }
    name=document.getElementById("dob").value;
    if(name==""){
      return alert('Enter DOB !');
    }
    name=document.getElementById("age").value;
    if(name==""){
      return alert('Enter Age ! ');
    }
    name=document.getElementById("address").value;
    if(name==""){
      return alert('Enter Address ! ');
    }
    name=document.getElementById("pic").value;
    if(name==""){
      return alert('Attach file ! ');
    }
  }