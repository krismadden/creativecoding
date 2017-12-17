using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Collections.Generic;

public class SpheresManager : MonoBehaviour {

	public GameObject spherePrefab;
	List<GameObject> mySpheres = new List<GameObject>();

	// Use this for initialization
	void Start () {

		for(int x = 0; x < 20; x++){
			for(int y = 0; y < 10; y++){
				for(int z = 0; z < 10; z++){
					mySpheres.Add ( Instantiate(spherePrefab, new Vector3(x*.225f,y*.225f,z*.225f), Quaternion.identity));
				}
			}
		}

	}
	
	// Update is called once per frame
	void Update () {



		if (Input.GetKeyDown ("a")) {
			foreach (GameObject sphere in mySpheres) {
				sphere.GetComponent<Rigidbody> ().isKinematic = false;
			}
		}else if (Input.GetKeyDown ("s")) {
			foreach (GameObject sphere in mySpheres) {
				sphere.GetComponent<Rigidbody> ().isKinematic = true;
			}
		}

		RaycastHit hit;
		Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

		if( /*Input.GetMouseButtonDown(0) &&*/  Physics.Raycast( ray, out hit) && hit.transform.tag == "Sphere" ){
			foreach (GameObject sphere in mySpheres) {
				Vector3 repel = sphere.transform.position-hit.transform.position ;
				float dist = repel.magnitude;
				if (dist < .9f) {
					repel.Normalize ();
					sphere.GetComponent<Sphere> ().addVelocity (repel*dist*.1f);
				}

			}
		}


	}
}
