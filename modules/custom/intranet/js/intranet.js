(function ($) {

	Drupal.behaviors.intranet = {
  	attach: function (context, settings) {
			// NOTE: it is not working reliably.
			//$(document).ready(function () {
			//	var element_id = 'li.admin-menu-action.admin-menu-account > a';
			//	$(element_id).attr('href', 'javascript:void(0);');
			//});

			// NOTE: after siwtching to ssl, the <div id=""> of search bar, it should be <div id="arts-staff-dropdown-site-search">
			// Buy why?
			$(document).ready(function(){
				var class_id = ".col-2.rightside.float_right";
				var needed_id = "arts-staff-dropdown-site-search";
				$(class_id).attr("id", needed_id);

				console.log('test');	
			});

  	}
	};

}(jQuery));
