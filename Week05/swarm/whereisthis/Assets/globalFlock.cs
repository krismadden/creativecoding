using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class globalFlock : MonoBehaviour {

	public GameObject horsePrefab;
	public GameObject goalPrefab;
	public static int fieldSize = 5;

	static int numHorse = 10;
	public static GameObject[] allHorse = new GameObject[numHorse];

	public static Vector3 goalPos = Vector3.zero;

	// Use this for initialization
	void Start () {
		for (int i = 0; i < numHorse; i++) {
			Vector3 pos = new Vector3 (Random.Range (-fieldSize, fieldSize),
				              			Random.Range (-fieldSize, fieldSize),
				              			Random.Range (-fieldSize, fieldSize));
			allHorse [i] = (GameObject)Instantiate (horsePrefab, pos, Quaternion.identity);
		}
		
	}
	
	// Update is called once per frame
	void Update () {
		if(Random.Range(0,10000) < 50){
			goalPos = new Vector3 (Random.Range (-fieldSize, fieldSize),
									Random.Range (-fieldSize, fieldSize),
									Random.Range (-fieldSize, fieldSize));
			goalPrefab.transform.position = goalPos;
		}
	}
}
