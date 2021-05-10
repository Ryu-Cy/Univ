using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    private int count;

    public GameObject obj;

    // Start is called before the first frame update
    void Start()
    {
        count = 0;  
    }

    // Update is called once per frame
    void Update()
    {
        int a;

        ++count;
        a = count % 100;

        if (a == 1)
        {
            for (int i = 0; i < 1; i++)
            {
                float randomX = Random.Range(-5.0f, 5.0f);
                Instantiate(obj, new Vector3(randomX, 1.5f, 50.0f), Quaternion.identity);
            }
        }
    }
}
