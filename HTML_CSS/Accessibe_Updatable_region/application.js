var configureTabSelection = function(){
  $("#services, #about, #contact").hide().attr("aria-hidden", true);
  $("#welcome").attr("aria-hidden", false);

  $("nav ul").click(function(event){
    var target = $(event.target);
    if(target.is("a")){
      event.preventDefault();
      if($(target.attr("href")).attr("aria-hidden")){
        activeTab(target.attr("href"));
      };
    };
  });
};

var activeTab = function(selector){
  $("[aria-hidden=false]").hide().attr("aria-hidden", true);
  $(selector).show().attr("aria-hidden", false);
};

configureTabSelection();
