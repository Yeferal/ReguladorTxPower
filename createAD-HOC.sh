echo '';
read -p "Escriba el nombre de la red: " nameRed;
echo '';
read -sp "Escriba la contraseña de la red: " passRed;


interfaceHost='interface=wlp2s0';
driverHost='driver=nl80211';
ssidHost='ssid='$nameRed;
bridgeHost='bridge=br0';
howmodeHost='hw_mode=g';
channelHost='channel=6';
macaddrHost='macaddr_acl=0';
ignoredHost='ignore_broadcast_ssid=0';
authHost='auth_algs=1';
wpaHost='wpa=3';
wpapassHost='wpa_passphrase='$passRed;
wpakeyHost='wpa_key_mgmt=WPA-PSK WPA-PSK=SHA256';
wpapairwiswHost='wpa_pairwise=TKIP';
rsnHost='rsn_pairwise=CCMP';

echo 'cat > my_wlan.conf';
cat > my_wlan.conf
echo $interfaceHost;
echo $driverHost;
echo $ssidHost;

#echo $txtHostapd;