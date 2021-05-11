using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StartButton : MonoBehaviour
{
    public GameObject eneSpawn;
    public GameObject itemSpawn;

    // Start is called before the first frame update
    void Start()
    {
        Time.timeScale = 0;

        eneSpawn.SetActive(false);
        itemSpawn.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void OnClickStartButton()
    {
        Time.timeScale = 1;
        Destroy(gameObject, 0);
        eneSpawn.SetActive(true);
        itemSpawn.SetActive(true);
    }
}
