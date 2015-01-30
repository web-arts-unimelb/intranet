(function ($) {

	Drupal.behaviors.zintranet = {
  	attach: function (context, settings) {
			//console.log(context);		
			//console.log(settings);
			$(document).ready(function () {
				var element_id = 'li.admin-menu-action.admin-menu-account > a';
				$(element_id).attr('href', 'javascript:void(0);');
			});
  	}
	};

}(jQuery));
