
//IIFE
(function(){
  var names = ["Yaakov", "John", "Jen", "Jason", "Paul", "Frank", "Larry", "Paula", "Laura", "Jim"];

  //loop 
  for (var indx in names) {
    //select lowercase of firt letter from name array
    var firstLetter = names[indx].charAt(0).toLowerCase(); 

    if (firstLetter === 'j') {
      byeSpeaker.speak(names[indx]);
    } else {
      helloSpeaker.speak(names[indx]);
    }
  }

})();
