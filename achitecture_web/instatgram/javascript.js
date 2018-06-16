
$( document ).ready(function() {
        var clic = 0;


        console.log( "ready!" );
        $("#infos").hide();
        $('#test').click(function() {

        var texteRecherche = document.getElementById("texte").value;
        if (texteRecherche == "trkyldz72"){
          getInfo("256786540.8f8b3ff.f2ca2766092247d5a1b5aba81d030047",256786540);
          getPhotos("256786540.8f8b3ff.f2ca2766092247d5a1b5aba81d030047",256786540);
        }else if(texteRecherche == "wass_workout"){
          getInfo("2990470892.2523aaf.31ab00b9eea541dd88ad697ff17bb290", 2990470892);
          getPhotos("2990470892.2523aaf.31ab00b9eea541dd88ad697ff17bb290", 2990470892);
        }




        $('.card-profile-stats-more-link').click(function(e){
          e.preventDefault();
          if ( $(".card-profile-stats-more-content").is(':hidden') ) {
            $('.card-profile-stats-more-link').find('i').removeClass('fa-angle-down').addClass('fa-angle-up');
          } else {
            $('.card-profile-stats-more-link').find('i').removeClass('fa-angle-up').addClass('fa-angle-down');
          }
          $(this).next('.card-profile-stats-more-content').slideToggle();
        });
      });
    });


  function getInfo(tok, clientId){
    var token = tok,
      userid = clientId;

      $("#infos").show();
      $.ajax({
        url: 'https://api.instagram.com/v1/users/' + userid,
        dataType: 'jsonp',
        type: 'GET',
        data: {access_token: token},
        success: function(data){

          console.log(data);

          $(".card-profile-stats-intro-pic").append('<img class="card-profile-stats-intro-pic" src="'+ data.data["profile_picture"] + '" alt="profile-image"/>');
          $(".card-profile-stats-intro-content").append('<h3>' + data.data["full_name"]+ '</h3>');
          $(".card-profile-stats-intro-content").append('<h5>' + data.data["username"]+ '</h5>');
          $(".card-profile-stats-more-content").append('<p>' + data.data["bio"] + '</p>');

          $(".card-profile-stats-container").append('<div class="card-profile-stats-statistic"><span class="stat" >' + data.data.counts["media"] + '</span>' + '<p>media</p><br/></div>');
          $(".card-profile-stats-container").append('<div class="card-profile-stats-statistic"><span class="stat" >' + data.data.counts["follows"] + '</span>' + '<p>Abonnements</p><br/></div>');
          $(".card-profile-stats-container").append('<div class="card-profile-stats-statistic"><span class="stat" >' + data.data.counts["followed_by"] + '</span>' + '<p>Abonnés</p><br/></div>');

      },
      error: function(data){
        console.log(data);
        $("#infos").hide();
      }
      });
  }

  function getPhotos(tok, clientId){
        var token = tok,
        userid = clientId,
        num_photos = 20,
        i = 0,
        compteur = 0;

        $.ajax({
          url: 'https://api.instagram.com/v1/users/' + userid + '/media/recent',
          dataType: 'jsonp',
          type: 'GET',
          data: {access_token: token,  count: num_photos},
          success: function(data){

            console.log(data);

            for( x in data.data ){
              if(data.data[x].type == "video"){
                $("#images").append('<video class="floating-box" id = "video'+i+' width="320" height="320" controls><source src="'+data.data[x].videos.standard_resolution.url+'" type = "video/mp4" >  Votre navigateur ne supporte pas les vidéos. </video>');
              }else
                $("#images").append('<img class="floating-box" id = "image'+i+' src="'+data.data[x].images.low_resolution.url+'"/>');
              if(data.data[x].location!= null){
                console.log("ajout");
                console.log(data.data[x].location.latitude);
                console.log(data.data[x].location.longitude);
                ajouter(data.data[x].location.latitude, data.data[x].location.longitude);
              }
              i+=1;

          }

        },
        error: function(data){
          console.log(data);

        }
      });

  }

  function lancerVideo(id){
    var video = document.getElementById(id);
    if(video.played)
      video.play();
    else
      video.pause();

  }
  var marker;
  map,
  pos;
  function initMap() {
    pos = {lat:  48.866667, lng: 2.333333};
    map = new google.maps.Map(document.getElementById('map'), {
      zoom: 3,
      center: pos
    });
  }

  function ajouter(lat,long) {
    pos = {lat : lat, lng: long};
    marker = new google.maps.Marker({
      position: pos,
      map: map
    });
}





//256786540.8f8b3ff.f2ca2766092247d5a1b5aba81d030047
//token google maps  AIzaSyB8aoUhYE2btpQ7L-FXw09i2WbUVRRLbDY
//https://termsfeed.com/privacy-policy/d6c18aecbf35970453c5a0bc70df8a1d : politique de confidentialité
