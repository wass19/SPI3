

  $("div").click(function() {
      
      var token = '256786540.035ecb8.94eece0bc94a4c6d81b8beb656be6421', // learn how to obtain it below
          userid = 256786540, // User ID - get it in source HTML of your Instagram profile or look at the next example :)
          num_photos = 4; // how much photos do you want to get
          alert("bonsoier1");
      $.ajax({
      	url: 'https://api.instagram.com/v1/users/' + userid + '/media/recent', // or /users/self/media/recent for Sandbox
      	dataType: 'jsonp',
      	type: 'GET',
      	data: {access_token: token, count: num_photos},
      	success: function(data){
       		console.log(data);
      		for( x in data.data ){
      			$('navbar-nav ml-auto').append('<li><img src="'+data.data[x].images.low_resolution.url+'"></li>'); // data.data[x].images.low_resolution.url - URL of image, 306х306
      			// data.data[x].images.thumbnail.url - URL of image 150х150
      			// data.data[x].images.standard_resolution.url - URL of image 612х612
      			// data.data[x].link - Instagram post URL
      		}
      	},
      	error: function(data){
      		console.log(data); // send the error notifications to console
      	}
      });
  });
