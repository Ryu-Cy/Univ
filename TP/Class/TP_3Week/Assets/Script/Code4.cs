﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Code4 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (transform.position.y < 1.0f)
            Destroy(gameObject, 0);
    }
}
