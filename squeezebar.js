(function ($) {
	
	var delay = Drupal.settings.squeezebar.delay;

	var stub_showing = false;
	
	function squeezebar_show() { 
	    if(stub_showing) {
	     	$('.squeezebar-stub').slideUp('fast', function() {
				$('.squeezebar').slideDown('fast'); 
				$('body').animate({ "marginTop": "2.4em" }, 'fast');
			}); 
	    }
	    else {
	      	$('.squeezebar').slideDown('fast'); 
	      	$('body').animate({"marginTop": "2.4em"}, 'fast');
	    }
	}
	
	function squeezebar_hide() {
		$('body').animate({"marginTop": "0px"}, 'fast'); 
	    $('.squeezebar').slideUp('fast', function() {
	    	$('.squeezebar-stub').slideDown('fast'); 
	    	stub_showing = true;
	    }); 
	}
	
	$().ready(function() {
		$('.squeezebar-close').click(function(){ squeezebar_hide() });
		$('.squeezebar-open').click(function(){ squeezebar_show() });
	
	    window.setTimeout(function() {
	    	squeezebar_show();
	    }, delay);
	});

	
})(jQuery);
