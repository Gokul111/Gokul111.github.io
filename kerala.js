<script type="text/javascript" >
  function validate(p1,p2,us)
{
  if(us.length==0 || p1.length==0 || p2.length==0)
      { alert("fill out all the fields");}
    else{
    if(p1==p2)
      {  confirm("Are you sure to sign in?");

       }
    else
    {
      alert("password mismatch!! , re enter");
    }}
    
}
function check()
{
  alert("Login Successfull");
}
</script>