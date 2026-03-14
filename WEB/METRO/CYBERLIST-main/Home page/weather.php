<?php
function getWeather($latitude, $longitude) {
  $url = "https://api.open-meteo.com/v1/forecast?latitude=$latitude&longitude=$longitude&current_weather=true";
    
  // Initialize cURL session
  $ch = curl_init($url);
    
  // Set cURL options
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    
  // Execute cURL request and get response
  $response = curl_exec($ch);
    
  // Check if the request was successful
  if(curl_errno($ch)) {
    return ['error' => 'Curl error: ' . curl_error($ch)];
  }
    
  // Close the cURL session
  curl_close($ch);
    
  // Decode the JSON response
  return json_decode($response, true);
}
?>