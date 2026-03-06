using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class gmGameRules : MonoBehaviour
{
    public Transform playerStart;
    public GameObject playerPrefab;
    // Start is called before the first frame update
    void Start()
    {
        GameObject spawnPlayer = 
        Instantiate(playerPrefab, playerStart.position, playerStart.rotation);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
