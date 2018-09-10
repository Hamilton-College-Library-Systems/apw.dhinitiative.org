/**
 * @file
 * Resizable transcription window behavior.
 */
(function ($) {

  Drupal.behaviors.resize_transcription_window = {
    attach: function(context, settings) {
      $("#apwa_inline_webform_target_wrapper").resizable({
        handles: "w",
        // From https://forum.jquery.com/topic/jquery-ui-resizable-iframefix
        start:function(event,ui){
          $("iframe").each(function() {
            $('<div class="ui-resizable-iframeFix" style="background: #fff;"></div>')
              .css({
                width: this.offsetWidth+"px", height: this.offsetHeight+"px",
                position: "absolute", opacity: "0.001", zIndex: 1000
              })
              .css($(this).offset())
              .appendTo("body");
          });
        },
        stop: function(event,ui){
          //Remove frame helpers
          $("div.ui-resizable-iframeFix").each(function() { this.parentNode.removeChild(this); });
        },

      });
    }
  };
})(jQuery);
