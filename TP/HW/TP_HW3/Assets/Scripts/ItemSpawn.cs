using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ItemSpawn : MonoBehaviour
{
    public GameObject PowerItem;
    public GameObject LifeItem;

    private int count1;
    private int count2;

    // Start is called before the first frame update
    void Start()
    {
        count1 = 0;
        count2 = 0;
    }

    // Update is called once per frame
    void Update()
    {
        int a, b;

        ++count1;
        ++count2;
        a = count1 % 1500;
        b = count2 % 1000;

        for (int i = 0; i < 1; i++) 
        {
            float randomX = Random.Range(-5.0f, 5.0f);
            if (a == 1)
                Instantiate(PowerItem, new Vector3(randomX, 1.5f, 50.0f), Quaternion.identity);
            else if (b == 1)
                Instantiate(LifeItem, new Vector3(randomX, 1.5f, 50.0f), Quaternion.identity);
        }
    }
}
