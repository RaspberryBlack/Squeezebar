(function ($) {
	
	console.log(Drupal.settings.squeezebar.key);

	var stub_showing = false;
	
	function squeezebar_show() { 
	    if(stub_showing) {
	     	$('.squeezebar-stub').slideUp('fast', function() {
				$('.squeezebar').show(/* 'bounce', { times:3, distance:15 },*/ 100); 
				$('body').animate({ "marginTop": "2.4em" }, 100);
			}); 
	    }
	    else {
	      	$('.squeezebar').show(/* 'bounce', { times:3, distance:15 },*/ 100); 
	      	$('body').animate({"marginTop": "2.4em"}, 100);
	    }
	}
	
	function squeezebar_hide() { 
	    $('.squeezebar').slideUp('fast', function() {
	    	$('.squeezebar-stub').show(/* 'bounce', { times:3, distance:15 }, */ 100);  
	    	stub_showing = true;
	    }); 
	
	    if( $(window).width() > 1024 ) {
	      	$('body').animate({"marginTop": "0px"}, 100); // if width greater than 1024 pull up the body
	    }
	}
	
	$().ready(function() {
		$('.squeezebar-close').click(function(){ squeezebar_hide() });
		$('.squeezebar-open').click(function(){ squeezebar_show() });
	
	    window.setTimeout(function() {
	    	squeezebar_show();
	    }, 1000);
	});

	
})(jQuery);
