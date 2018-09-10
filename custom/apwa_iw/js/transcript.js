/**
 * @file
 * Resizable transcription window behavior.
 */
(function ($) {

  Drupal.behaviors.transcript = {
    attach: function(context, settings) {
      var load_target = function(pid, ds, target) {
        url = '/islandora/object/'+pid+'/apwa_transcript/'+ds+'/getajax';
        $(target).load(url);
        console.log(url);
      };
      $('#transcript_link').click(function() {

        load_target(settings.apwa_iw.pid, settings.apwa_iw.transcript_ds, settings.apwa_iw.target);
        $('#islandora_object_display_wrapper').addClass('display-webform');
        $('#transcript_link').hide();
      });
    }
  };
})(jQuery);
