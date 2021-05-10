using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Code1 : MonoBehaviour
{
    public int hp = 0;
    public float a = 1.5f;
    public string b = "Ryu";
    public bool f = false;

    void Awake()
    {
        hp = 100;
        Debug.Log("Hello World");
    }

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("hp = " + hp);
        Debug.Log("a = " + a);
        Debug.Log("b = " + b);
        Debug.Log("f = " + f);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
