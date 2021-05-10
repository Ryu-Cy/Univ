using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Code3 : MonoBehaviour
{
    public GameObject obj;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        float randomX = Random.Range(-5f, 5f);

        Instantiate(obj, new Vector3(randomX, 5, 0), Quaternion.identity);
    }
}
